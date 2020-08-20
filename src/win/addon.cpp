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

    //string to LPCWSTR
    //std::wstring stemp = s2ws(filePath);
    //LPCWSTR result = stemp.c_str();

    //獲取驅動器的物理類型  該函數返回驅動器類型
    UINT uDriveType = GetDriveType(filePath.c_str());
    switch (uDriveType)
    {
    case DRIVE_UNKNOWN: //驅動器類型不確定
        return Napi::String::New(env, "unknow");
        break;
    case DRIVE_NO_ROOT_DIR: //根目錄無效
        return Napi::String::New(env, "fail");
        break;
    case DRIVE_REMOVABLE: //可移動設備， 比如U盤
        return Napi::String::New(env, "removable");
        break;
    case DRIVE_FIXED: //固定的驅動;例如,一個硬盤或閃存驅動器
        return Napi::String::New(env, "fixed");
        break;
    case DRIVE_REMOTE: //遠程(網絡)驅動器
        return Napi::String::New(env, "network-drive");
        break;
    case DRIVE_CDROM: //cd - rom驅動器
        return Napi::String::New(env, "cdrom");
        break;
    case DRIVE_RAMDISK: //RAM磁盤
        return Napi::String::New(env, "ramdisk");
        break;
    default:
        return Napi::String::New(env, "unknow");
        break;
    }
}

Napi::Object Init(Napi::Env env, Napi::Object exports)
{
    exports.Set(Napi::String::New(env, "pathType"), Napi::Function::New(env, PathType));
    return exports;
}

NODE_API_MODULE(addon, Init)
