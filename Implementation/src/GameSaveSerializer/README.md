# GameSaveSerializer

This module is responsible for loading and saving files to implement persistence between game sessions.
Saving is done via multiple threads to prevent interruptions to gameplay. Loading is done with a single thread. 
