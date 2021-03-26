#include <napi.h>
#include <string>
#include <sys/mount.h>
#include <sys/param.h>

Napi::Value PathType(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();

    if (info.Length() < 1)
    {
        Napi::TypeError::New(env, "Wrong number of arguments(only one argument)")
            .ThrowAsJavaScriptException();
        return env.Null();
    }

    if (!info[0].IsString())
    {
        Napi::TypeError::New(env, "Wrong arguments(only string and it is a file path. e.g: C:\\abcd)").ThrowAsJavaScriptException();
        return env.Null();
    }

    std::string filePath = info[0].As<Napi::String>().ToString();

    struct statfs fileStat;
    if (statfs(filePath.data(), &fileStat) == 0)
    {
        return Napi::String::New(env, fileStat.f_fstypename);
    }
    else
    {
        return Napi::String::New(env, "fail");
    }

    return Napi::String::New(env, "fail");
}

Napi::Object Init(Napi::Env env, Napi::Object exports)
{
    exports.Set(Napi::String::New(env, "pathType"), Napi::Function::New(env, PathType));
    return exports;
}

NODE_API_MODULE(addon, Init)
