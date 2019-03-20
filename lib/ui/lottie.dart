// Copyright 2013 The Flutter Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

/// Skia backed Lottie Animation player for Dart.
///
/// To use, import `dart:ui`.

part of dart.ui;

class LottieAnimation extends NativeFieldWrapperClass2 {
  @pragma('vm:entry-point')
  LottieAnimation(String json) : assert(json != null) {
    _constructor(json);
  }
  void _constructor(String json) native 'LottieAnimation_constructor';

  void drawFrame(Canvas canvas, double progress, double width, double height) {
    assert(canvas != null);
    assert(progress != null && progress <= 1.0 && progress >= 0);
    assert(width != null && width > 0);
    assert(height != null && height > 0);
    _drawFrame(canvas, progress, width, height);
  }
  void _drawFrame(Canvas canvas, double progress, double width, double height) native 'LottieAnimation_drawFrame';

  double get duration native 'LottieAnimation_duration';
}