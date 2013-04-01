#include <jni.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <vorbis/codec.h>
#include <android/log.h>

#ifndef _Included_org_xiph_vorbis_VorbisDecoder
#define _Included_org_xiph_vorbis_VorbisDecoder
#ifdef __cplusplus
extern "C" {
#endif

//Starts the decoding from a vorbis bitstream to pcm
JNIEXPORT int JNICALL Java_org_xiph_vorbis_decoder_VorbisDecoder_startDecoding
  (JNIEnv *env, jclass cls, jobject vorbisDataFeed);

//Stops the vorbis data feed
void stopDecodeFeed(JNIEnv *env, jobject* vorbisDataFeed, jmethodID* stopMethodId);

//Throws an exception to the java layer with th specified error code and stops the decode feed
void throwDecodeException(JNIEnv *env, const int code, jobject* vorbisDataFeed, jmethodID* stopMethodId);

//Reads raw vorbis data from the jni callback
int readVorbisDataFromVorbisDataFeed(JNIEnv *env, jobject* vorbisDataFeed, jmethodID* readVorbisDataMethodId, char* buffer, int length);

//Writes the pcm data to the Java layer
void writePCMDataFromVorbisDataFeed(JNIEnv *env, jobject* vorbisDataFeed, jmethodID* writePCMDataMethodId, ogg_int16_t* buffer, int bytes);

//Starts the decode feed with the necessary information about sample rates, channels, etc about the stream
void start(JNIEnv *env, jobject *vorbisDataFeed, jmethodID* startMethodId, long sampleRate, long channels, char* vendor);

//Starts reading the header information
void startReadingHeader(JNIEnv *env, jobject *vorbisDataFeed, jmethodID* startReadingHeaderMethodId);

#ifdef __cplusplus
}
#endif
#endif