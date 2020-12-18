# Todo List

|Library|Function|Used in|Present in C++|
|---|---|---|---|
|Numpy|ones|stat_robust::run|?|
|Numpy|median|stat_robust::run|?|
|Numpy|std|stat_robust::run, meanstd_robust::run|?|
|Numpy|less_equal|stat_robust::run|?|
|Numpy|sum|stat_robust::run|?|
|Numpy|argsort|stat_robust::run|?|
|Numpy|arange|stat_robust::run|?|
|Numpy|connect|stat_robust::run|?|
|Numpy|greater|stat_robust::run|?|
|Numpy|compress|stat_robust::run|?|
|Numpy|max|stat_robust::run|?|
|Numpy|min|stat_robust::run|?|
|Numpy|mean|stat_robust::run, stat_robust::rms, meanstd_robust::run|?|
|Numpy|sqrt|stat_robust::rms|?|
|Numpy|sort|meanstd_robust::run, determinescaling, setlevels|?|
|Numpy|rms|meanstd_robust::run|?|
|Numpy|searchsorted|meanstd_robust::run, setlevels|?|
|Numpy|clip|clip2, setlevels, imscale1, imscale2, RGB2im, Trilogy::loadstamps, Trilogy::determinescalings, Trilogy::determinescalings2, Trilogy::showsample|?|
|Numpy|flat|determinescaling|?|
|Numpy|isnan|determinescaling|?|
|Numpy|take|setlevels|?|
|Numpy|log10|imscale1, imscale2|?|
|Numpy|ravel|imscale1, imscale2, grayimage|?|
|Numpy|abs|da, imscale2|?|
|Numpy|dot|adjsat|?|
|Numpy|transpose|RGB2im, grayimage|?|
|Numpy|zeros|RGBscale2im, offsetarray, Trilogy::loadstamps|?|
|PIL|Image.fromarray|RGB2im|?|
|PIL|Image.putdata|grayimage|?|
|PIL|Image.resize|Trilogy::makethumbnail1|?|
|scipy|optimize.golden|imscale2|?|
|string|rfind|decapfile|?|
|string|split|stringsplitatof, str2num|?|
|string|atoi|str2num|?|
|string|atof|str2num|?|
|string|strip|str2num, Trilogy::determinescalings2|?|
|string|rstrip|Trilogy::determinescalings|?|
|Operator|** (element-wise power)|stat_robust::run|?|