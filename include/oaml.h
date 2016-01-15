#ifndef __OAML_H__
#define __OAML_H__


//
// Definitions
//

#define OAML_VOLUME_MIN		0
#define OAML_VOLUME_MAX		100

#define OAML_VOLUME_DEFAULT	50

enum {
	COND_TYPE_EQUAL		= 0,
	COND_TYPE_GREATER	= 1,
	COND_TYPE_LESS		= 2,
	COND_TYPE_RANGE		= 3
};

//
// Internal declarations
//

class oamlBase;

//
// Main class
//

class oamlApi {
private:
	oamlBase *oaml;

public:
	oamlApi();
	~oamlApi();

	/** Initilize the Open Adaptive Music Library with specific path
	 *  @return returns 0, or -1 on error
	 */
	int Init(const char *pathToMusic);

	/** Shutdown the library */
	void Shutdown();

	void SetAudioFormat(int freq, int channels, int bytesPerSample);
	void SetVolume(int vol);
	int GetVolume();

	/** Play a music track by name (recommended) or id
	 *  @return returns 0, or -1 on error
	 */
	int PlayTrack(const char *name);
	int PlayTrackId(int id);

	/** Stop playing any track currently playing */
	void StopPlaying();

	/** Check if a track is playing */
	bool IsTrackPlaying(const char *name);
	bool IsTrackPlayingId(int id);

	/** Check if any track is playing */
	bool IsPlaying();

	/** Add tension that triggers different aspects of the music */
	void AddTension(int value);

	/** Sets a condition that affects the main loop */
	void SetMainLoopCondition(int value);

	/** Set a condition */
	void SetCondition(int id, int value);

	/** Main function to call form the internal game audio manager */
	void MixToBuffer(void *buffer, int size);

	/** Update */
	void Update();

	/** Debugging functions */
	void SetDebugClipping(bool option);
	void SetMeasureDecibels(bool option);
	void SetWriteAudioAtShutdown(bool option);
};

#endif /* __OAML_H__ */
