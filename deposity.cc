#include <node.h>
#include <v8.h>
#include <string>
#include <vector>

using namespace v8;

string sources[2] = {"selam","naber"};

void Method(const v8::FunctionCallbackInfo<Value>& args) {
  Isolate* isolate = Isolate::GetCurrent();
  HandleScope scope(isolate);
  args.GetReturnValue().Set(String::NewFromUtf8(isolate,'libs/jquery/jquery/dist/jquery.js,libs/angular/angular/angular.js,libs/angular/angular-animate/angular-animate.js,libs/angular/angular-aria/angular-aria.js,libs/angular/angular-cookies/angular-cookies.js,libs/angular/angular-messages/angular-messages.js,libs/angular/angular-resource/angular-resource.js,libs/angular/angular-sanitize/angular-sanitize.js,libs/angular/angular-touch/angular-touch.js,libs/angular/angular-material/angular-material.js,libs/angular/angular-ui-router/release/angular-ui-router.js,libs/angular/ngstorage/ngStorage.js,libs/angular/angular-ui-utils/ui-utils.js,libs/angular/angular-bootstrap/ui-bootstrap-tpls.js,libs/angular/oclazyload/dist/ocLazyLoad.js,libs/angular/angular-translate/angular-translate.js,libs/angular/angular-translate-loader-static-files/angular-translate-loader-static-files.js,libs/angular/angular-translate-storage-cookie/angular-translate-storage-cookie.js,libs/angular/angular-translate-storage-local/angular-translate-storage-local.js,libs/jquery/bootstrap/dist/js/bootstrap.js,libs/angular/ng-infinite-scroll/ng-infinite-scroll.js,libs/angular/angularjs-toaster/toaster.js,js/app.js,js/config.lazyload.js,js/config.js,js/config.router.js,js/main.js,js/app/**/*.js,js/controllers/**/*.js,js/directives/**/*.js,js/filters/**/*.js,js/services/**/*.js'));

 // scope.close(String::NewFromUtf8(isolate, "deposity ready"));
}

void Init(Handle<Object> exports) {
  Isolate* isolate = Isolate::GetCurrent();
  exports->Set(String::NewFromUtf8(isolate, "deposity"),
      FunctionTemplate::New(isolate, Method)->GetFunction());
}

NODE_MODULE(deposity, Init)