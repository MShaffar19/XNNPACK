// Auto-generated file. Do not edit!
//   Template: src/qs8-gemm/c16-neon-mlal-padal.c.in
//   Generator: tools/xngen
//
// Copyright 2021 Google LLC
//
// This source code is licensed under the BSD-style license found in the
// LICENSE file in the root directory of this source tree.

#include <assert.h>

#include <arm_neon.h>

#include <xnnpack/common.h>
#include <xnnpack/gemm.h>


void xnn_qs8_gemm_minmax_ukernel_1x8c16__neon_mlal_padal(
    size_t mr,
    size_t nc,
    size_t kc,
    const int8_t* restrict a,
    size_t a_stride,
    const void* restrict w,
    int8_t* restrict c,
    size_t cm_stride,
    size_t cn_stride,
    const union xnn_qs8_gemm_params params[restrict XNN_MIN_ELEMENTS(1)]) XNN_DISABLE_TSAN
{
  assert(mr != 0);
  assert(mr <= 1);
  assert(nc != 0);
  assert(kc != 0);
  assert(kc % sizeof(int8_t) == 0);
  assert(a != NULL);
  assert(w != NULL);
  assert(c != NULL);

  const int8_t* a0 = a;
  int8_t* c0 = c;

  do {
    int32x4_t vacc0x0 = vld1q_lane_s32(w, vmovq_n_s32(0), 0); w = (const void*) ((uintptr_t) w + 1 * sizeof(int32_t));
    int32x4_t vacc0x1 = vld1q_lane_s32(w, vmovq_n_s32(0), 0); w = (const void*) ((uintptr_t) w + 1 * sizeof(int32_t));
    int32x4_t vacc0x2 = vld1q_lane_s32(w, vmovq_n_s32(0), 0); w = (const void*) ((uintptr_t) w + 1 * sizeof(int32_t));
    int32x4_t vacc0x3 = vld1q_lane_s32(w, vmovq_n_s32(0), 0); w = (const void*) ((uintptr_t) w + 1 * sizeof(int32_t));
    int32x4_t vacc0x4 = vld1q_lane_s32(w, vmovq_n_s32(0), 0); w = (const void*) ((uintptr_t) w + 1 * sizeof(int32_t));
    int32x4_t vacc0x5 = vld1q_lane_s32(w, vmovq_n_s32(0), 0); w = (const void*) ((uintptr_t) w + 1 * sizeof(int32_t));
    int32x4_t vacc0x6 = vld1q_lane_s32(w, vmovq_n_s32(0), 0); w = (const void*) ((uintptr_t) w + 1 * sizeof(int32_t));
    int32x4_t vacc0x7 = vld1q_lane_s32(w, vmovq_n_s32(0), 0); w = (const void*) ((uintptr_t) w + 1 * sizeof(int32_t));

    size_t k = kc;
    while (k >= 8 * sizeof(int8_t)) {
      const int8x8_t va0 = vld1_s8(a0); a0 += 8;

      const int8x16_t vb0 = vld1q_s8(w); w = (const void*) ((uintptr_t) w + 16 * sizeof(int8_t));

      int16x8_t vprod0x0 = vmull_s8(vget_low_s8(vb0), va0);
      vprod0x0 = vmlal_s8(vprod0x0, vget_high_s8(vb0), va0);
      vacc0x0 = vpadalq_s16(vacc0x0, vprod0x0);
      const int8x16_t vb2 = vld1q_s8(w); w = (const void*) ((uintptr_t) w + 16 * sizeof(int8_t));

      int16x8_t vprod0x2 = vmull_s8(vget_low_s8(vb2), va0);
      vprod0x2 = vmlal_s8(vprod0x2, vget_high_s8(vb2), va0);
      vacc0x2 = vpadalq_s16(vacc0x2, vprod0x2);
      const int8x16_t vb4 = vld1q_s8(w); w = (const void*) ((uintptr_t) w + 16 * sizeof(int8_t));

      int16x8_t vprod0x4 = vmull_s8(vget_low_s8(vb4), va0);
      vprod0x4 = vmlal_s8(vprod0x4, vget_high_s8(vb4), va0);
      vacc0x4 = vpadalq_s16(vacc0x4, vprod0x4);
      const int8x16_t vb6 = vld1q_s8(w); w = (const void*) ((uintptr_t) w + 16 * sizeof(int8_t));

      int16x8_t vprod0x6 = vmull_s8(vget_low_s8(vb6), va0);
      vprod0x6 = vmlal_s8(vprod0x6, vget_high_s8(vb6), va0);
      vacc0x6 = vpadalq_s16(vacc0x6, vprod0x6);

      k -= 8 * sizeof(int8_t);
    }
    if XNN_UNLIKELY(k != 0) {
      const int8x8_t va0 = vld1_s8(a0); a0 += k;

      const int8x8_t vb0 = vld1_s8(w); w = (const void*) ((uintptr_t) w + 8 * sizeof(int8_t));

      const int16x8_t vprod0x0 = vmull_s8(vb0, va0);
      vacc0x0 = vpadalq_s16(vacc0x0, vprod0x0);
      const int8x8_t vb1 = vld1_s8(w); w = (const void*) ((uintptr_t) w + 8 * sizeof(int8_t));

      const int16x8_t vprod0x1 = vmull_s8(vb1, va0);
      vacc0x1 = vpadalq_s16(vacc0x1, vprod0x1);
      const int8x8_t vb2 = vld1_s8(w); w = (const void*) ((uintptr_t) w + 8 * sizeof(int8_t));

      const int16x8_t vprod0x2 = vmull_s8(vb2, va0);
      vacc0x2 = vpadalq_s16(vacc0x2, vprod0x2);
      const int8x8_t vb3 = vld1_s8(w); w = (const void*) ((uintptr_t) w + 8 * sizeof(int8_t));

      const int16x8_t vprod0x3 = vmull_s8(vb3, va0);
      vacc0x3 = vpadalq_s16(vacc0x3, vprod0x3);
      const int8x8_t vb4 = vld1_s8(w); w = (const void*) ((uintptr_t) w + 8 * sizeof(int8_t));

      const int16x8_t vprod0x4 = vmull_s8(vb4, va0);
      vacc0x4 = vpadalq_s16(vacc0x4, vprod0x4);
      const int8x8_t vb5 = vld1_s8(w); w = (const void*) ((uintptr_t) w + 8 * sizeof(int8_t));

      const int16x8_t vprod0x5 = vmull_s8(vb5, va0);
      vacc0x5 = vpadalq_s16(vacc0x5, vprod0x5);
      const int8x8_t vb6 = vld1_s8(w); w = (const void*) ((uintptr_t) w + 8 * sizeof(int8_t));

      const int16x8_t vprod0x6 = vmull_s8(vb6, va0);
      vacc0x6 = vpadalq_s16(vacc0x6, vprod0x6);
      const int8x8_t vb7 = vld1_s8(w); w = (const void*) ((uintptr_t) w + 8 * sizeof(int8_t));

      const int16x8_t vprod0x7 = vmull_s8(vb7, va0);
      vacc0x7 = vpadalq_s16(vacc0x7, vprod0x7);
    }

    #if XNN_ARCH_ARM64
      const int32x4_t ab0x0 = vpaddq_s32(vacc0x0, vacc0x1);
      const int32x4_t cd0x0 = vpaddq_s32(vacc0x2, vacc0x3);
      int32x4_t vacc0x0123 = vpaddq_s32(ab0x0, cd0x0);
    #else
      const int32x2_t ab_low0x0  = vpadd_s32(vget_low_s32(vacc0x0),  vget_low_s32(vacc0x1));
      const int32x2_t ab_high0x0 = vpadd_s32(vget_high_s32(vacc0x0), vget_high_s32(vacc0x1));
      const int32x2_t cd_low0x0  = vpadd_s32(vget_low_s32(vacc0x2), vget_low_s32(vacc0x3));
      const int32x2_t cd_high0x0 = vpadd_s32(vget_high_s32(vacc0x2), vget_high_s32(vacc0x3));
      const int32x2_t ab0x0 = vadd_s32(ab_low0x0, ab_high0x0);
      const int32x2_t cd0x0 = vadd_s32(cd_low0x0, cd_high0x0);
      int32x4_t vacc0x0123 = vcombine_s32(ab0x0, cd0x0);
    #endif
    #if XNN_ARCH_ARM64
      const int32x4_t ab0x4 = vpaddq_s32(vacc0x4, vacc0x5);
      const int32x4_t cd0x4 = vpaddq_s32(vacc0x6, vacc0x7);
      int32x4_t vacc0x4567 = vpaddq_s32(ab0x4, cd0x4);
    #else
      const int32x2_t ab_low0x4  = vpadd_s32(vget_low_s32(vacc0x4),  vget_low_s32(vacc0x5));
      const int32x2_t ab_high0x4 = vpadd_s32(vget_high_s32(vacc0x4), vget_high_s32(vacc0x5));
      const int32x2_t cd_low0x4  = vpadd_s32(vget_low_s32(vacc0x6), vget_low_s32(vacc0x7));
      const int32x2_t cd_high0x4 = vpadd_s32(vget_high_s32(vacc0x6), vget_high_s32(vacc0x7));
      const int32x2_t ab0x4 = vadd_s32(ab_low0x4, ab_high0x4);
      const int32x2_t cd0x4 = vadd_s32(cd_low0x4, cd_high0x4);
      int32x4_t vacc0x4567 = vcombine_s32(ab0x4, cd0x4);
    #endif

    const int32x4_t vmultiplier = vld1q_dup_s32(&params->neon.multiplier);
    vacc0x0123 = vqrdmulhq_s32(vacc0x0123, vmultiplier);
    vacc0x4567 = vqrdmulhq_s32(vacc0x4567, vmultiplier);

    const int32x4_t vright_shift = vld1q_dup_s32(&params->neon.right_shift);
    const int32x4_t vzero_shift_mask = vreinterpretq_s32_u32(vceqq_s32(vright_shift, vmovq_n_s32(0)));
    vacc0x0123 = vsraq_n_s32(vacc0x0123, vbicq_s32(vacc0x0123, vzero_shift_mask), 31);
    vacc0x4567 = vsraq_n_s32(vacc0x4567, vbicq_s32(vacc0x4567, vzero_shift_mask), 31);

    vacc0x0123 = vrshlq_s32(vacc0x0123, vright_shift);
    vacc0x4567 = vrshlq_s32(vacc0x4567, vright_shift);

    const int16x8_t voutput_zero_point = vld1q_dup_s16(&params->neon.output_zero_point);
#if XNN_ARCH_ARM64
    const int16x8_t vacc0x01234567 = vqaddq_s16(vqmovn_high_s32(vqmovn_s32(vacc0x0123), vacc0x4567), voutput_zero_point);
    int8x8_t vout0x01234567 = vqmovn_s16(vacc0x01234567);
#else
    const int16x8_t vacc0x01234567 = vqaddq_s16(vcombine_s16(vqmovn_s32(vacc0x0123), vqmovn_s32(vacc0x4567)), voutput_zero_point);

    int8x8_t vout0x01234567 = vqmovn_s16(vacc0x01234567);
#endif
    const int8x8_t voutput_min = vld1_dup_s8(&params->neon.output_min);
    const int8x8_t voutput_max = vld1_dup_s8(&params->neon.output_max);

    vout0x01234567 = vmax_s8(vout0x01234567, voutput_min);

    vout0x01234567 = vmin_s8(vout0x01234567, voutput_max);

    if (nc >= 8) {
      vst1_s8(c0 + 0, vout0x01234567);

      c0 = (int8_t*) ((uintptr_t) c0 + cn_stride);

      a0 = (const int8_t*) ((uintptr_t) a0 - kc);

      nc -= 8;
    } else {
      if (nc & 4) {
        vst1_lane_u32(__builtin_assume_aligned(c0, 1), vreinterpret_u32_s8(vout0x01234567), 0); c0 += 4;
        vout0x01234567 = vext_s8(vout0x01234567, vout0x01234567, 4);
      }
      if (nc & 2) {
        vst1_lane_u16(__builtin_assume_aligned(c0, 1), vreinterpret_u16_s8(vout0x01234567), 0); c0 += 2;
        vout0x01234567 = vext_s8(vout0x01234567, vout0x01234567, 2);
      }
      if (nc & 1) {
        vst1_lane_s8(c0, vout0x01234567, 0);
      }

      nc = 0;
    }
  } while (nc != 0);
}
