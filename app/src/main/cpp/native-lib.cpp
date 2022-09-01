#include <jni.h>
#include <string>

extern "C" JNIEXPORT jstring JNICALL
Java_com_crabfibber_project_mpdev_MainActivity_stringFromJNI(
        JNIEnv *env,
        jobject /* this */) {
    std::string hello = "Hello from C++";
    return env->NewStringUTF(hello.c_str());
}


extern "C" {
#include <string>
#include <libavcodec/avcodec.h>
#include <libavformat/avformat.h>
#include <libavfilter/avfilter.h>
JNIEXPORT jstring JNICALL
Java_com_crabfibber_project_mpdev_MainActivity_getAllCodecFromJNI(JNIEnv *env, jobject thiz) {
    char info[40000] = {0};
    const AVCodec *p;
    void *i = 0;
//    while((p = av_codec_next(NULL))){
//
//    }

    while ((p = av_codec_iterate(&i))) {
        if (av_codec_is_encoder(p)) {
            sprintf(info, "%sencode:", info);
        } else if (av_codec_is_decoder(p)) {
            sprintf(info, "%sdecode:", info);
        } else {
            sprintf(info, "%sunknown:", info);
        }
        switch (p->type) {
            case AVMEDIA_TYPE_VIDEO:
                sprintf(info, " %s(video):", info);
                break;
            case AVMEDIA_TYPE_AUDIO:
                sprintf(info, " %s(audio):", info);
                break;
            default:
                sprintf(info, " %s(other):", info);
                break;
        }
        sprintf(info, "%s[%s]\n", info, p->name);
    }
    return env->NewStringUTF(info);
}
}
