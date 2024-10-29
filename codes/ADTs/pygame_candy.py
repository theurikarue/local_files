import pygame
import sys
import random
import math

pygame.init()

WIDTH, HEIGHT = 800, 900
DISPENSER_WIDTH, DISPENSER_HEIGHT = 300, 600
CANDY_SIZE = 50
MAX_CANDIES = 10

# Colors
BG_COLOR = (240, 248, 255)  # Alice Blue
DISPENSER_COLOR = (230, 230, 250)  # Lavender
DISPENSER_OUTLINE = (138, 43, 226)  # Blue Violet
SPRING_COLOR = (147, 112, 219)  # Medium Purple
BUTTON_COLOR = (106, 90, 205)  # Slate Blue
BUTTON_HOVER_COLOR = (72, 61, 139)  # Dark Slate Blue
TEXT_COLOR = (25, 25, 112)  # Midnight Blue

screen = pygame.display.set_mode((WIDTH, HEIGHT))
pygame.display.set_caption("Deluxe Candy Dispenser Stack")

class Particle:
    def __init__(self, x, y, color):
        self.x = x
        self.y = y
        self.color = color
        self.size = random.randint(2, 5)
        self.speed = random.uniform(0.5, 2)
        self.angle = random.uniform(0, 2 * math.pi)

    def move(self):
        self.x += math.cos(self.angle) * self.speed
        self.y += math.sin(self.angle) * self.speed
        self.size -= 0.1
        return self.size > 0

    def draw(self, surface):
        pygame.draw.circle(surface, self.color, (int(self.x), int(self.y)), int(self.size))

class Button:
    def __init__(self, x, y, width, height, text, action):
        self.rect = pygame.Rect(x, y, width, height)
        self.text = text
        self.action = action
        self.is_hovered = False

    def draw(self, surface):
        color = BUTTON_HOVER_COLOR if self.is_hovered else BUTTON_COLOR
        pygame.draw.rect(surface, color, self.rect, border_radius=10)
        pygame.draw.rect(surface, TEXT_COLOR, self.rect, 2, border_radius=10)
        font = pygame.font.Font(None, 28)
        text_surf = font.render(self.text, True, TEXT_COLOR)
        text_rect = text_surf.get_rect(center=self.rect.center)
        surface.blit(text_surf, text_rect)

    def handle_event(self, event):
        if event.type == pygame.MOUSEMOTION:
            self.is_hovered = self.rect.collidepoint(event.pos)
        elif event.type == pygame.MOUSEBUTTONDOWN and event.button == 1:
            if self.rect.collidepoint(event.pos):
                self.action()

class CandyDispenserStack:
    def __init__(self):
        self.stack = []
        self.spring_height = 150
        self.spring_width = 120
        self.spring_x = WIDTH // 2
        self.spring_y = HEIGHT - 200
        self.particles = []
        self.push_button = Button(WIDTH // 2 - 130, HEIGHT - 80, 120, 50, "Push", self.push)
        self.pop_button = Button(WIDTH // 2 + 10, HEIGHT - 80, 120, 50, "Pop", self.pop)
        self.candy_colors = [
            (255, 105, 180),  # Hot Pink
            (255, 69, 0),     # Orange Red
            (255, 215, 0),    # Gold
            (50, 205, 50),    # Lime Green
            (30, 144, 255)    # Dodger Blue
        ]

    def draw(self, surface):
        # Draw dispenser body
        dispenser_rect = pygame.Rect((WIDTH - DISPENSER_WIDTH) // 2, HEIGHT - DISPENSER_HEIGHT - 150,
                                     DISPENSER_WIDTH, DISPENSER_HEIGHT)
        pygame.draw.rect(surface, DISPENSER_COLOR, dispenser_rect, border_radius=20)
        pygame.draw.rect(surface, DISPENSER_OUTLINE, dispenser_rect, 4, border_radius=20)

        # Draw dispenser opening
        opening_rect = pygame.Rect((WIDTH - DISPENSER_WIDTH - 40) // 2, HEIGHT - DISPENSER_HEIGHT - 190,
                                   DISPENSER_WIDTH + 40, 80)
        pygame.draw.arc(surface, DISPENSER_OUTLINE, opening_rect, math.pi, 2 * math.pi, 4)

        # Draw spring
        points = []
        coils = 60
        compressed = len(self.stack) / MAX_CANDIES
        height = self.spring_height * (1 - 0.5 * compressed)

        for i in range(coils * 2 + 1):
            x = self.spring_x + self.spring_width / 2 * math.sin(math.pi * i / coils)
            y = self.spring_y - height * i / (coils * 2)
            points.append((x, y))

        pygame.draw.lines(surface, SPRING_COLOR, False, points, 4)

        # Draw candies
        for i, candy in enumerate(self.stack):
            y_pos = HEIGHT - 220 - (i + 1) * CANDY_SIZE
            self.draw_candy(surface, candy, WIDTH // 2, y_pos)

        # Draw particles
        self.particles = [p for p in self.particles if p.move()]
        for particle in self.particles:
            particle.draw(surface)

        # Draw buttons
        self.push_button.draw(surface)
        self.pop_button.draw(surface)

    def draw_candy(self, surface, color, x, y):
        pygame.draw.circle(surface, color, (x, y), CANDY_SIZE // 2)
        pygame.draw.circle(surface, (255, 255, 255), (x - CANDY_SIZE // 5, y - CANDY_SIZE // 5), CANDY_SIZE // 8)  # Highlight

    def push(self):
        if len(self.stack) < MAX_CANDIES:
            candy_color = random.choice(self.candy_colors)
            self.stack.append(candy_color)
            self.add_particles(WIDTH // 2, HEIGHT - DISPENSER_HEIGHT - 150, candy_color)
        else:
            print("Stack is full!")

    def pop(self):
        if self.stack:
            candy_color = self.stack.pop()
            self.add_particles(WIDTH // 2, HEIGHT - 220 - len(self.stack) * CANDY_SIZE, candy_color)
        else:
            print("Stack is empty!")

    def add_particles(self, x, y, color):
        for _ in range(20):
            self.particles.append(Particle(x, y, color))

    def handle_event(self, event):
        self.push_button.handle_event(event)
        self.pop_button.handle_event(event)

def main():
    clock = pygame.time.Clock()
    dispenser = CandyDispenserStack()
    font = pygame.font.Font(None, 48)

    while True:
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                pygame.quit()
                sys.exit()
            dispenser.handle_event(event)

        screen.fill(BG_COLOR)
        dispenser.draw(screen)

        # Draw title
        title = font.render("Deluxe Candy Dispenser", True, TEXT_COLOR)
        screen.blit(title, (WIDTH // 2 - title.get_width() // 2, 20))

        pygame.display.flip()
        clock.tick(60)

if __name__ == "__main__":
    main()
    