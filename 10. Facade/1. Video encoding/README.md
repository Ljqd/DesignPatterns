# Problem: Video encoding

Converting video from one format to another is a multi-step process that requires the use of a whole series of auxiliary tools.

Instead, you can implement the Facade design template, which provides the user with just one simple method, hiding behind it a whole system with video codecs, audio mixers, and other equally complex objects.

This method should take as input the file to be transcoded and the format to which the file should be converted

```java
public VideoFile convert(VideoFile file, Codec codec) {
    ...
    return newVideoFile;
}
```

Refactor the code ![Link](https://github.com/krenevych/design-patterns-java/tree/main/Java/lab11_Facade/task_3_1/src) using the Facade design pattern to simplify the client's work with a complex video conversion library.