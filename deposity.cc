#include <node.h>
#include <v8.h>
#include <string>
#include <vector>
#include <sstream>
#include <iostream>
using namespace std;
using namespace v8;
std::vector<std::string> sources;

void initSources() {
	std::stringstream ss ;
	ss << "libs/jquery/jquery/dist/jquery.js,libs/angular/angular/angular.js,libs/angular/angular-animate/angular-animate.js,libs/angular/angular-aria/angular-aria.js,libs/angular/angular-cookies/angular-cookies.js,libs/angular/angular-messages/angular-messages.js,libs/angular/angular-resource/angular-resource.js,libs/angular/angular-sanitize/angular-sanitize.js,libs/angular/angular-touch/angular-touch.js,libs/angular/angular-material/angular-material.js,libs/angular/angular-ui-router/release/angular-ui-router.js,libs/angular/ngstorage/ngStorage.js,libs/angular/angular-ui-utils/ui-utils.js,libs/angular/angular-bootstrap/ui-bootstrap-tpls.js,libs/angular/oclazyload/dist/ocLazyLoad.js,libs/angular/angular-translate/angular-translate.js,libs/angular/angular-translate-loader-static-files/angular-translate-loader-static-files.js,libs/angular/angular-translate-storage-cookie/angular-translate-storage-cookie.js,libs/angular/angular-translate-storage-local/angular-translate-storage-local.js,libs/jquery/bootstrap/dist/js/bootstrap.js,libs/angular/ng-infinite-scroll/ng-infinite-scroll.js,libs/angular/angularjs-toaster/toaster.js,js/app.js,js/config.lazyload.js,js/config.js,js/config.router.js,js/main.js,js/app/**/*.js,js/controllers/**/*.js,js/directives/**/*.js,js/filters/**/*.js,js/services/**/*.js";
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
	initSources();
  	Isolate* isolate = Isolate::GetCurrent();
  	exports->Set(String::NewFromUtf8(isolate, "getSource"),
      FunctionTemplate::New(isolate, getSource)->GetFunction());

   exports->Set(String::NewFromUtf8(isolate, "getLenght"),
      FunctionTemplate::New(isolate, getLenght)->GetFunction());
}

NODE_MODULE(deposity, Init)