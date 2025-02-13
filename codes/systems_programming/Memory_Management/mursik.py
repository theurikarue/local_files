import pygame
import sys
import time

# Initialize Pygame
pygame.init()

# Screen Setup
SCREEN_WIDTH = 800
SCREEN_HEIGHT = 600
screen = pygame.display.set_mode((SCREEN_WIDTH, SCREEN_HEIGHT))
pygame.display.set_caption("Mursik Advertisement Simulation")

# Colors
BACKGROUND_COLOR = (230, 220, 200)  # Warm beige
MILK_COLOR = (200, 200, 200)  # Grey milk color
GUARD_COLOR = (100, 50, 0)  # Dark brown for guard

# Fonts
font = pygame.font.Font(None, 36)

class MursikScene:
    def __init__(self):
        # Load images (replace with actual image paths)
        self.grandma_img = pygame.Surface((200, 300))
        self.grandma_img.fill((150, 100, 50))  # Placeholder grandma color
        
        self.kimu_img = pygame.Surface((200, 300))
        self.kimu_img.fill((100, 150, 50))  # Placeholder Kimu color
        
        self.guard_img = pygame.Surface((100, 200))
        self.guard_img.fill(GUARD_COLOR)

    def scene_establishing(self):
        """Simulate establishing scene with grandma and Kimu"""
        screen.fill(BACKGROUND_COLOR)
        
        # Draw background elements
        guards_background = pygame.Surface((SCREEN_WIDTH, 100))
        guards_background.fill((150, 120, 90))
        screen.blit(guards_background, (0, SCREEN_HEIGHT - 100))
        
        # Draw characters
        screen.blit(self.grandma_img, (100, 200))
        screen.blit(self.kimu_img, (500, 200))
        
        pygame.display.flip()
        pygame.time.delay(2000)

    def milk_pouring(self):
        """Animate milk pouring from guard to cup"""
        cup_rect = pygame.Rect(350, 400, 100, 150)
        guard_rect = pygame.Rect(200, 300, 50, 100)
        
        # Pouring animation
        for i in range(0, 100, 10):
            screen.fill(BACKGROUND_COLOR)
            pygame.draw.rect(screen, GUARD_COLOR, guard_rect)
            pygame.draw.rect(screen, MILK_COLOR, 
                             (cup_rect.x, cup_rect.y + (150 - i), 
                              cup_rect.width, i))
            pygame.display.flip()
            pygame.time.delay(100)

    def drinking_moment(self):
        """Simulate Kimu drinking and expressing satisfaction"""
        # Draw Kimu with cup
        screen.fill(BACKGROUND_COLOR)
        screen.blit(self.kimu_img, (400, 200))
        
        # Add text "Kongoi"
        kongoi_text = font.render("Kongoi!", True, (0, 0, 0))
        screen.blit(kongoi_text, (400, 100))
        
        pygame.display.flip()
        pygame.time.delay(2000)

    def run_simulation(self):
        """Run complete advertisement simulation"""
        try:
            # Scene 1: Establishing Shot
            self.scene_establishing()
            
            # Scene 2: Milk Pouring
            self.milk_pouring()
            
            # Scene 3: Drinking Moment
            self.drinking_moment()
            
            # Final pause
            pygame.time.delay(2000)
        
        except Exception as e:
            print(f"Simulation error: {e}")
        finally:
            pygame.quit()
            sys.exit()

# Run the simulation
if __name__ == "__main__":
    simulation = MursikScene()
    simulation.run_simulation()
