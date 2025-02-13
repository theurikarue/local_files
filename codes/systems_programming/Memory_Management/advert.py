import win32com.client

# Connect to Adobe Premiere Pro
premiere = win32com.client.Dispatch("Premiere.Application")

def create_sequence(sequence_name):
    """Create a new sequence in Premiere Pro."""
    project = premiere.GetProject()
    sequences = project.Sequences
    sequence = sequences.Add(sequence_name)
    return sequence

def add_media_to_timeline(sequence, media_file_path, start_time, track):
    """Add media to the sequence timeline."""
    project = premiere.GetProject()
    media_file = project.ImportFile(media_file_path)
    clip = sequence.AddClip(media_file, start_time, track)
    return clip

def add_text_overlay(sequence, text, start_time, end_time, track):
    """Add a text overlay."""
    graphics_track = sequence.GetGraphicsTrack(track)
    text_layer = graphics_track.AddTextClip(text, start_time, end_time)
    return text_layer

def add_audio_to_timeline(sequence, audio_file_path, start_time, track):
    """Add audio to the timeline."""
    project = premiere.GetProject()
    audio_file = project.ImportFile(audio_file_path)
    audio_clip = sequence.AddAudioClip(audio_file, start_time, track)
    return audio_clip

def create_video():
    """Automate video creation."""
    # Create a new sequence
    sequence = create_sequence("Mursik Story")

    # Add media clips
    add_media_to_timeline(sequence, r"C:\path\to\kimu_sipping.jpg", 0, 1)
    add_media_to_timeline(sequence, r"C:\path\to\grandma_pouring.jpg", 5, 2)
    add_media_to_timeline(sequence, r"C:\path\to\cup_filling.jpg", 10, 3)
    add_media_to_timeline(sequence, r"C:\path\to\kimu_drinking.jpg", 15, 4)
    add_media_to_timeline(sequence, r"C:\path\to\grandma_smiling.jpg", 20, 5)
    add_media_to_timeline(sequence, r"C:\path\to\background_guard.jpg", 25, 6)

    # Add text overlays
    add_text_overlay(sequence, "A truly refreshing taste and aroma", 5, 10, 1)
    add_text_overlay(sequence, "Celebrate tradition with every sip", 25, 30, 1)

    # Add audio
    add_audio_to_timeline(sequence, r"C:\path\to\background_music.mp3", 0, 1)
    add_audio_to_timeline(sequence, r"C:\path\to\milk_pouring_sound.wav", 10, 2)
    add_audio_to_timeline(sequence, r"C:\path\to\kongoi_audio.wav", 15, 3)

    # Export the sequence (add export functionality if needed)
    print("Video creation complete!")

# Run the automation script
create_video()
