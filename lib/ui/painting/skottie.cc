// Copyright 2013 The Flutter Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "flutter/lib/ui/painting/skottie.h"

#include "third_party/tonic/dart_args.h"
#include "third_party/tonic/dart_binding_macros.h"
#include "third_party/tonic/dart_library_natives.h"

namespace blink {

static void SkottieAnimation_constructor(Dart_NativeArguments args) {
  DartCallConstructor(&SkottieAnimation::Create, args);
}

IMPLEMENT_WRAPPERTYPEINFO(ui, SkottieAnimation);

#define FOR_EACH_BINDING(V)       \
  V(SkottieAnimation, drawFrame)  \
  V(SkottieAnimation, duration)

FOR_EACH_BINDING(DART_NATIVE_CALLBACK)

void SkottieAnimation::RegisterNatives(tonic::DartLibraryNatives* natives) {
  natives->Register(
      {{"SkottieAnimation_constructor", SkottieAnimation_constructor, 2, true},
       FOR_EACH_BINDING(DART_REGISTER_NATIVE)});
}

SkottieAnimation::SkottieAnimation() {}

SkottieAnimation::~SkottieAnimation() {}

void SkottieAnimation::drawFrame(const Canvas* canvas,
                                 double progress,
                                 double height,
                                 double width) {
  FML_DCHECK(canvas);
  FML_DCHECK(progress >= 0);
  FML_DCHECK(height > 0);
  FML_DCHECK(width > 0);
  auto skia_canvas = canvas->canvas();
  FML_DCHECK(skia_canvas);
  animation_->seek(progress);
  SkRect bounds = SkRect::MakeWH(width, height);
  animation_->render(skia_canvas, &bounds);
}

double SkottieAnimation::duration() {
  return animation_->duration();
}

}  // namespace blink
