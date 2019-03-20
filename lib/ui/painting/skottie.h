// Copyright 2013 The Flutter Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef FLUTTER_LIB_UI_PAINTING_SKOTTIE_H_
#define FLUTTER_LIB_UI_PAINTING_SKOTTIE_H_

#include "flutter/lib/ui/dart_wrapper.h"
#include "flutter/lib/ui/painting/canvas.h"
#include "third_party/skia/modules/skottie/include/Skottie.h"

namespace blink {

class SkottieAnimation : public RefCountedDartWrappable<SkottieAnimation> {
  DEFINE_WRAPPERTYPEINFO();
  FML_FRIEND_MAKE_REF_COUNTED(SkottieAnimation);

 public:
  ~SkottieAnimation() override;

static fml::RefPtr<SkottieAnimation> Create(const std::string& data) {
  fml::RefPtr<SkottieAnimation> animation =
      fml::MakeRefCounted<SkottieAnimation>();
  animation->animation_ = skottie::Animation::Make(data.c_str(), data.length());
  return animation;
}

  sk_sp<skottie::Animation> animation() { return animation_; }

  void drawFrame(const Canvas* canvas, double progress, double height, double width);

  double duration();

  static void RegisterNatives(tonic::DartLibraryNatives* natives);

 private:
  SkottieAnimation();
  sk_sp<skottie::Animation> animation_;
};

}  // namespace blink

#endif  // FLUTTER_LIB_UI_PAINTING_SKOTTIE_H_
