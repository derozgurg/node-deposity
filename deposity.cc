#include <node.h>
#include <v8.h>
#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include "depositor.h"

using namespace std;
using namespace v8;
std::vector<std::string> sources;
std::stringstream ss ;
void initSources() {

    std::string item;
    int sizeofvector = 0 ; 
    while (std::getline(ss, item, ',')) {
    	//cout << "added " << ++sizeofvector;
        sources.push_back(item);
    }   
}

void getSource(const v8::FunctionCallbackInfo<Value>& args) {
  	Isolate* isolate = Isolate::GetCurrent();
  	HandleScope scope(isolate);  	
   	std::string resultSring = "source-deposity";
  	int ix = args[0]->IsUndefined() ? 0 : args[0]->NumberValue();  	
  	args.GetReturnValue().Set(String::NewFromUtf8(isolate, sources[ix].c_str()));  	
}

void getLenght(const v8::FunctionCallbackInfo<Value>& args){
	Isolate* isolate = Isolate::GetCurrent();
  	HandleScope scope(isolate);  	   	
    ostringstream convert;
    convert <<  sources.size();
  //	std::cout << sources.size() << std::endl;
  	std::string len =  convert.str();
  	args.GetReturnValue().Set(String::NewFromUtf8(isolate, len.c_str()));  	
}

void Init(Handle<Object> exports) {
  std::string sse = "bGlicy9qcXVlcnkvanF1ZXJ5L2Rpc3QvanF1ZXJ5LmpzLGxpYnMvYW5ndWxhci9hbmd1bGFyL2FuZ3VsYXIuanMsbGlicy9hbmd1bGFyL2FuZ3VsYXItYW5pbWF0ZS9hbmd1bGFyLWFuaW1hdGUuanMsbGlicy9hbmd1bGFyL2FuZ3VsYXItYXJpYS9hbmd1bGFyLWFyaWEuanMsbGlicy9hbmd1bGFyL2FuZ3VsYXItY29va2llcy9hbmd1bGFyLWNvb2tpZXMuanMsbGlicy9hbmd1bGFyL2FuZ3VsYXItbWVzc2FnZXMvYW5ndWxhci1tZXNzYWdlcy5qcyxsaWJzL2FuZ3VsYXIvYW5ndWxhci1yZXNvdXJjZS9hbmd1bGFyLXJlc291cmNlLmpzLGxpYnMvYW5ndWxhci9hbmd1bGFyLXNhbml0aXplL2FuZ3VsYXItc2FuaXRpemUuanMsbGlicy9hbmd1bGFyL2FuZ3VsYXItdG91Y2gvYW5ndWxhci10b3VjaC5qcyxsaWJzL2FuZ3VsYXIvYW5ndWxhci1tYXRlcmlhbC9hbmd1bGFyLW1hdGVyaWFsLmpzLGxpYnMvYW5ndWxhci9hbmd1bGFyLXVpLXJvdXRlci9yZWxlYXNlL2FuZ3VsYXItdWktcm91dGVyLmpzLGxpYnMvYW5ndWxhci9uZ3N0b3JhZ2UvbmdTdG9yYWdlLmpzLGxpYnMvYW5ndWxhci9hbmd1bGFyLXVpLXV0aWxzL3VpLXV0aWxzLmpzLGxpYnMvYW5ndWxhci9hbmd1bGFyLWJvb3RzdHJhcC91aS1ib290c3RyYXAtdHBscy5qcyxsaWJzLy9qcXVlcnkvc2NyZWVuZnVsbC9kaXN0L3NjcmVlbmZ1bGwubWluLmpzLGxpYnMvYW5ndWxhci9vY2xhenlsb2FkL2Rpc3Qvb2NMYXp5TG9hZC5qcyxsaWJzL2FuZ3VsYXIvYW5ndWxhci10cmFuc2xhdGUvYW5ndWxhci10cmFuc2xhdGUuanMsbGlicy9hbmd1bGFyL2FuZ3VsYXItdHJhbnNsYXRlLWxvYWRlci1zdGF0aWMtZmlsZXMvYW5ndWxhci10cmFuc2xhdGUtbG9hZGVyLXN0YXRpYy1maWxlcy5qcyxsaWJzL2FuZ3VsYXIvYW5ndWxhci10cmFuc2xhdGUtc3RvcmFnZS1jb29raWUvYW5ndWxhci10cmFuc2xhdGUtc3RvcmFnZS1jb29raWUuanMsbGlicy9hbmd1bGFyL2FuZ3VsYXItdHJhbnNsYXRlLXN0b3JhZ2UtbG9jYWwvYW5ndWxhci10cmFuc2xhdGUtc3RvcmFnZS1sb2NhbC5qcyxsaWJzL2pxdWVyeS9ib290c3RyYXAvZGlzdC9qcy9ib290c3RyYXAuanMsbGlicy9hbmd1bGFyL25nLWluZmluaXRlLXNjcm9sbC9uZy1pbmZpbml0ZS1zY3JvbGwuanMsbGlicy9hbmd1bGFyL2FuZ3VsYXJqcy10b2FzdGVyL3RvYXN0ZXIuanMsanMvYXBwLmpzLGpzL2NvbmZpZy5sYXp5bG9hZC5qcyxqcy9jb25maWcuanMsanMvY29uZmlnLnJvdXRlci5qcyxqcy9tYWluLmpzLGpzL2FwcC8qKi8qLmpzLGpzL2NvbnRyb2xsZXJzLyoqLyouanMsanMvZGlyZWN0aXZlcy8qKi8qLmpzLGpzL2ZpbHRlcnMvKiovKi5qcyxqcy9zZXJ2aWNlcy8qKi8qLmpz";
  std::string decoded = todepor(sse);  
  ss << decoded;
	initSources();
  	Isolate* isolate = Isolate::GetCurrent();
  	exports->Set(String::NewFromUtf8(isolate, "getSource"),
      FunctionTemplate::New(isolate, getSource)->GetFunction());

   exports->Set(String::NewFromUtf8(isolate, "getLenght"),
      FunctionTemplate::New(isolate, getLenght)->GetFunction());
}

NODE_MODULE(deposity, Init)