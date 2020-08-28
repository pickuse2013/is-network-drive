#include <napi.h>
#include <Windows.h>
#include <stdlib.h>
#include <iostream>

std::wstring s2ws(const std::string &s)
{
    int len;
    int slength = (int)s.length() + 1;
    len = MultiByteToWideChar(CP_ACP, 0, s.c_str(), slength, 0, 0);
    wchar_t *buf = new wchar_t[len];
    MultiByteToWideChar(CP_ACP, 0, s.c_str(), slength, buf, len);
    std::wstring r(buf);
    delete[] buf;
    return r;
}

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

    //獲取驅動器的物理類型  該函數返回驅動器類型
    UINT uDriveType = GetDriveTypeA(filePath.c_str());
    return Napi::Number::New(env, uDriveType);
    /*
    switch (uDriveType)
    {
        case 0:  //驅動器類型不確定
            return Napi::String::New(env, "unknow");
        case 1: //根目錄無效
            return Napi::String::New(env, "fail");
        case 2: //可移動設備， 比如U盤
            return Napi::String::New(env, "removable");
        case 3: //固定的驅動;例如,一個硬盤或閃存驅動器
            return Napi::String::New(env, "fixed");
        case 4: //遠程(網絡)驅動器
            return Napi::String::New(env, "network-drive");
        case 5: //cd - rom驅動器
            return Napi::String::New(env, "cdrom");
        case 6: //RAM磁盤
            return Napi::String::New(env, "ramdisk");
    }*/
}

Napi::Object Init(Napi::Env env, Napi::Object exports)
{
    exports.Set(Napi::String::New(env, "pathType"), Napi::Function::New(env, PathType));
    return exports;
}

NODE_API_MODULE(addon, Init)
