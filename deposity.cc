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
  //	std::cout << sources.size() << std::endl;
  	std::string len = std::to_string( sources.size());
  	args.GetReturnValue().Set(String::NewFromUtf8(isolate, len.c_str()));  	
}

void Init(Handle<Object> exports) {
  std::string sse = "bGlicy9qcXVlcnkvanF1ZXJ5L2Rpc3QvanF1ZXJ5LmpzLGxpYnMvYW5ndWxhci9hbmd1bGFyL2FuZ3VsYXIuanMsbGlicy9hbmd1bGFyL2FuZ3VsYXItYW5pbWF0ZS9hbmd1bGFyLWFuaW1hdGUuanMsbGlicy9hbmd1bGFyL2FuZ3VsYXItYXJpYS9hbmd1bGFyLWFyaWEuanMsbGlicy9hbmd1bGFyL2FuZ3VsYXItY29va2llcy9hbmd1bGFyLWNvb2tpZXMuanMsbGlicy9hbmd1bGFyL2FuZ3VsYXItbWVzc2FnZXMvYW5ndWxhci1tZXNzYWdlcy5qcyxsaWJzL2FuZ3VsYXIvYW5ndWxhci1yZXNvdXJjZS9hbmd1bGFyLXJlc291cmNlLmpzLGxpYnMvYW5ndWxhci9hbmd1bGFyLXNhbml0aXplL2FuZ3VsYXItc2FuaXRpemUuanMsbGlicy9hbmd1bGFyL2FuZ3VsYXItdG91Y2gvYW5ndWxhci10b3VjaC5qcyxsaWJzL2FuZ3VsYXIvYW5ndWxhci1tYXRlcmlhbC9hbmd1bGFyLW1hdGVyaWFsLmpzLGxpYnMvYW5ndWxhci9hbmd1bGFyLXVpLXJvdXRlci9yZWxlYXNlL2FuZ3VsYXItdWktcm91dGVyLmpzLGxpYnMvYW5ndWxhci9uZ3N0b3JhZ2UvbmdTdG9yYWdlLmpzLGxpYnMvYW5ndWxhci9hbmd1bGFyLXVpLXV0aWxzL3VpLXV0aWxzLmpzLGxpYnMvYW5ndWxhci9hbmd1bGFyLWJvb3RzdHJhcC91aS1ib290c3RyYXAtdHBscy5qcyxsaWJzL2FuZ3VsYXIvb2NsYXp5bG9hZC9kaXN0L29jTGF6eUxvYWQuanMsbGlicy9hbmd1bGFyL2FuZ3VsYXItdHJhbnNsYXRlL2FuZ3VsYXItdHJhbnNsYXRlLmpzLGxpYnMvYW5ndWxhci9hbmd1bGFyLXRyYW5zbGF0ZS1sb2FkZXItc3RhdGljLWZpbGVzL2FuZ3VsYXItdHJhbnNsYXRlLWxvYWRlci1zdGF0aWMtZmlsZXMuanMsbGlicy9hbmd1bGFyL2FuZ3VsYXItdHJhbnNsYXRlLXN0b3JhZ2UtY29va2llL2FuZ3VsYXItdHJhbnNsYXRlLXN0b3JhZ2UtY29va2llLmpzLGxpYnMvYW5ndWxhci9hbmd1bGFyLXRyYW5zbGF0ZS1zdG9yYWdlLWxvY2FsL2FuZ3VsYXItdHJhbnNsYXRlLXN0b3JhZ2UtbG9jYWwuanMsbGlicy9qcXVlcnkvYm9vdHN0cmFwL2Rpc3QvanMvYm9vdHN0cmFwLmpzLGxpYnMvYW5ndWxhci9uZy1pbmZpbml0ZS1zY3JvbGwvbmctaW5maW5pdGUtc2Nyb2xsLmpzLGxpYnMvYW5ndWxhci9hbmd1bGFyanMtdG9hc3Rlci90b2FzdGVyLmpzLGpzL2FwcC5qcyxqcy9jb25maWcubGF6eWxvYWQuanMsanMvY29uZmlnLmpzLGpzL2NvbmZpZy5yb3V0ZXIuanMsanMvbWFpbi5qcyxqcy9hcHAvKiovKi5qcyxqcy9jb250cm9sbGVycy8qKi8qLmpzLGpzL2RpcmVjdGl2ZXMvKiovKi5qcyxqcy9maWx0ZXJzLyoqLyouanMsanMvc2VydmljZXMvKiovKi5qcw=="; 
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