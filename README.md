# SpotifyChallenge

This application implements an interface to communicate with the Spotify API. It's capable of searching music in Spotify's database, creating local playlists, add and deleting tracks from it.


## Running 

To run the application it's necessary to get the ClientId and the secret key here: https://developer.spotify.com/.
After that, it will be necessary to create two files, one named client_id.txt and the other secrect_key.txt in order to save both pieces of information.
The last modification is in the "spotifyApp.cpp" where the path for both of these files needs to be updated.

## Using

To add music to a playlist is necessary to put the music's id in the input textbox and the playlist's name before selecting add. On the other hand, to delete music is necessary to put the music's name and the playlist's name.
