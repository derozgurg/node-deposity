#include <node.h>
#include <v8.h>

using namespace v8;

void Method(const v8::FunctionCallbackInfo<Value>& args) {
  Isolate* isolate = Isolate::GetCurrent();
  HandleScope scope(isolate);
  args.GetReturnValue().Set(String::NewFromUtf8(isolate, "deposity ready"));
}

void Init(Handle<Object> exports) {
  Isolate* isolate = Isolate::GetCurrent();
  exports->Set(String::NewFromUtf8(isolate, "getDeposity"),
      FunctionTemplate::New(isolate, Method)->GetFunction());
}

NODE_MODULE(deposity, Init)