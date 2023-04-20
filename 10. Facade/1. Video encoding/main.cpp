#include <iostream>
#include <string>

#include "src/VideoConverter.h"

int main()
{
    std::string fileName = "youtubevideo.ogg";
    std::string format = "mp4";

    Buffer b1 = { "Byte buffer of video" };
    Buffer b2 = { "Byte buffer of audio" };

    VideoFile* videoFile = new VideoFile(fileName, b1, b2);

    Codec* codecMp4 = new MPEG4CompressionCodec();
    videoFile->play(codecMp4);

    VideoFile* videoFileConverted = VideoConverter::convert(videoFile, codecMp4);

    videoFileConverted->play(codecMp4);
}