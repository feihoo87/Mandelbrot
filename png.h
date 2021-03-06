#ifndef PNG_H
#define PNG_H

#define PNG_LIBPNG_VER_STRING "1.5.4"
#define PNG_HEADER_VERSION_STRING \
     " libpng version 1.5.4 - July 7, 2011\n"
#define PNG_LIBPNG_VER_SONUM   15
#define PNG_LIBPNG_VER_DLLNUM  15
#define PNG_LIBPNG_VER_MAJOR   1
#define PNG_LIBPNG_VER_MINOR   5
#define PNG_LIBPNG_VER_RELEASE 4
#define PNG_LIBPNG_VER_BUILD  0
#define PNG_LIBPNG_BUILD_ALPHA    1
#define PNG_LIBPNG_BUILD_BETA     2
#define PNG_LIBPNG_BUILD_RC       3
#define PNG_LIBPNG_BUILD_STABLE   4
#define PNG_LIBPNG_BUILD_RELEASE_STATUS_MASK 7
#define PNG_LIBPNG_BUILD_PATCH    8
#define PNG_LIBPNG_BUILD_PRIVATE 16
#define PNG_LIBPNG_BUILD_SPECIAL 32
#define PNG_LIBPNG_BUILD_BASE_TYPE PNG_LIBPNG_BUILD_BETA
#define PNG_LIBPNG_VER 10504
#ifndef PNGLCONF_H
#   include "pnglibconf.h"
#endif
#ifndef PNG_VERSION_INFO_ONLY
#  ifndef PNG_BUILDING_SYMBOL_TABLE
#    ifdef PNG_SETJMP_SUPPORTED
#      include <setjmp.h>
#    endif
#    ifdef PNG_CONVERT_tIME_SUPPORTED
#      include <time.h>
#    endif
#  endif
#  include "pngconf.h"
#endif
#ifdef PNG_USER_PRIVATEBUILD
#  define PNG_LIBPNG_BUILD_TYPE \
       (PNG_LIBPNG_BUILD_BASE_TYPE | PNG_LIBPNG_BUILD_PRIVATE)
#else
#  ifdef PNG_LIBPNG_SPECIALBUILD
#    define PNG_LIBPNG_BUILD_TYPE \
         (PNG_LIBPNG_BUILD_BASE_TYPE | PNG_LIBPNG_BUILD_SPECIAL)
#  else
#    define PNG_LIBPNG_BUILD_TYPE (PNG_LIBPNG_BUILD_BASE_TYPE)
#  endif
#endif
#ifndef PNG_VERSION_INFO_ONLY
#ifdef __cplusplus
extern "C" {
#endif
#define png_libpng_ver png_get_header_ver(NULL)
typedef char* png_libpng_version_1_5_4;
typedef struct png_color_struct
{
   png_byte red;
   png_byte green;
   png_byte blue;
} png_color;
typedef png_color FAR * png_colorp;
typedef PNG_CONST png_color FAR * png_const_colorp;
typedef png_color FAR * FAR * png_colorpp;

typedef struct png_color_16_struct
{
   png_byte index;    /* used for palette files */
   png_uint_16 red;   /* for use in red green blue files */
   png_uint_16 green;
   png_uint_16 blue;
   png_uint_16 gray;  /* for use in grayscale files */
} png_color_16;
typedef png_color_16 FAR * png_color_16p;
typedef PNG_CONST png_color_16 FAR * png_const_color_16p;
typedef png_color_16 FAR * FAR * png_color_16pp;

typedef struct png_color_8_struct
{
   png_byte red;   /* for use in red green blue files */
   png_byte green;
   png_byte blue;
   png_byte gray;  /* for use in grayscale files */
   png_byte alpha; /* for alpha channel files */
} png_color_8;
typedef png_color_8 FAR * png_color_8p;
typedef PNG_CONST png_color_8 FAR * png_const_color_8p;
typedef png_color_8 FAR * FAR * png_color_8pp;
typedef struct png_sPLT_entry_struct
{
   png_uint_16 red;
   png_uint_16 green;
   png_uint_16 blue;
   png_uint_16 alpha;
   png_uint_16 frequency;
} png_sPLT_entry;
typedef png_sPLT_entry FAR * png_sPLT_entryp;
typedef PNG_CONST png_sPLT_entry FAR * png_const_sPLT_entryp;
typedef png_sPLT_entry FAR * FAR * png_sPLT_entrypp;
typedef struct png_sPLT_struct
{
   png_charp name;           /* palette name */
   png_byte depth;           /* depth of palette samples */
   png_sPLT_entryp entries;  /* palette entries */
   png_int_32 nentries;      /* number of palette entries */
} png_sPLT_t;
typedef png_sPLT_t FAR * png_sPLT_tp;
typedef PNG_CONST png_sPLT_t FAR * png_const_sPLT_tp;
typedef png_sPLT_t FAR * FAR * png_sPLT_tpp;
#ifdef PNG_TEXT_SUPPORTED
typedef struct png_text_struct
{
   int  compression;
   png_charp key;
   png_charp text;
   png_size_t text_length;
   png_size_t itxt_length;
   png_charp lang;
   png_charp lang_key;
} png_text;
typedef png_text FAR * png_textp;
typedef PNG_CONST png_text FAR * png_const_textp;
typedef png_text FAR * FAR * png_textpp;
#endif
#define PNG_TEXT_COMPRESSION_NONE_WR -3
#define PNG_TEXT_COMPRESSION_zTXt_WR -2
#define PNG_TEXT_COMPRESSION_NONE    -1
#define PNG_TEXT_COMPRESSION_zTXt     0
#define PNG_ITXT_COMPRESSION_NONE     1
#define PNG_ITXT_COMPRESSION_zTXt     2
#define PNG_TEXT_COMPRESSION_LAST     3
typedef struct png_time_struct
{
   png_uint_16 year;
   png_byte month;
   png_byte day;
   png_byte hour;
   png_byte minute;
   png_byte second;
} png_time;
typedef png_time FAR * png_timep;
typedef PNG_CONST png_time FAR * png_const_timep;
typedef png_time FAR * FAR * png_timepp;
#if defined(PNG_UNKNOWN_CHUNKS_SUPPORTED) || \
    defined(PNG_HANDLE_AS_UNKNOWN_SUPPORTED)
typedef struct png_unknown_chunk_t
{
    png_byte name[5];
    png_byte *data;
    png_size_t size;
    png_byte location;
}
png_unknown_chunk;
typedef png_unknown_chunk FAR * png_unknown_chunkp;
typedef PNG_CONST png_unknown_chunk FAR * png_const_unknown_chunkp;
typedef png_unknown_chunk FAR * FAR * png_unknown_chunkpp;
#endif
#define PNG_HAVE_IHDR  0x01
#define PNG_HAVE_PLTE  0x02
#define PNG_AFTER_IDAT 0x08
typedef struct png_info_def png_info;
typedef png_info FAR * png_infop;
typedef PNG_CONST png_info FAR * png_const_infop;
typedef png_info FAR * FAR * png_infopp;
#define PNG_UINT_31_MAX ((png_uint_32)0x7fffffffL)
#define PNG_UINT_32_MAX ((png_uint_32)(-1))
#define PNG_SIZE_MAX ((png_size_t)(-1))
#define PNG_FP_1    100000
#define PNG_FP_HALF  50000
#define PNG_FP_MAX  ((png_fixed_point)0x7fffffffL)
#define PNG_FP_MIN  (-PNG_FP_MAX)
#define PNG_COLOR_MASK_PALETTE    1
#define PNG_COLOR_MASK_COLOR      2
#define PNG_COLOR_MASK_ALPHA      4
#define PNG_COLOR_TYPE_GRAY 0
#define PNG_COLOR_TYPE_PALETTE  (PNG_COLOR_MASK_COLOR | PNG_COLOR_MASK_PALETTE)
#define PNG_COLOR_TYPE_RGB        (PNG_COLOR_MASK_COLOR)
#define PNG_COLOR_TYPE_RGB_ALPHA  (PNG_COLOR_MASK_COLOR | PNG_COLOR_MASK_ALPHA)
#define PNG_COLOR_TYPE_GRAY_ALPHA (PNG_COLOR_MASK_ALPHA)
#define PNG_COLOR_TYPE_RGBA  PNG_COLOR_TYPE_RGB_ALPHA
#define PNG_COLOR_TYPE_GA  PNG_COLOR_TYPE_GRAY_ALPHA
#define PNG_COMPRESSION_TYPE_BASE 0
#define PNG_COMPRESSION_TYPE_DEFAULT PNG_COMPRESSION_TYPE_BASE
#define PNG_FILTER_TYPE_BASE      0
#define PNG_INTRAPIXEL_DIFFERENCING 64
#define PNG_FILTER_TYPE_DEFAULT   PNG_FILTER_TYPE_BASE
#define PNG_INTERLACE_NONE        0
#define PNG_INTERLACE_ADAM7       1
#define PNG_INTERLACE_LAST        2
#define PNG_OFFSET_PIXEL          0
#define PNG_OFFSET_MICROMETER     1
#define PNG_OFFSET_LAST           2
#define PNG_EQUATION_LINEAR       0
#define PNG_EQUATION_BASE_E       1
#define PNG_EQUATION_ARBITRARY    2
#define PNG_EQUATION_HYPERBOLIC   3
#define PNG_EQUATION_LAST         4
#define PNG_SCALE_UNKNOWN         0
#define PNG_SCALE_METER           1
#define PNG_SCALE_RADIAN          2
#define PNG_SCALE_LAST            3
#define PNG_RESOLUTION_UNKNOWN    0
#define PNG_RESOLUTION_METER      1
#define PNG_RESOLUTION_LAST       2
#define PNG_sRGB_INTENT_PERCEPTUAL 0
#define PNG_sRGB_INTENT_RELATIVE   1
#define PNG_sRGB_INTENT_SATURATION 2
#define PNG_sRGB_INTENT_ABSOLUTE   3
#define PNG_sRGB_INTENT_LAST       4
#define PNG_KEYWORD_MAX_LENGTH     79
#define PNG_MAX_PALETTE_LENGTH    256
#define PNG_INFO_gAMA 0x0001
#define PNG_INFO_sBIT 0x0002
#define PNG_INFO_cHRM 0x0004
#define PNG_INFO_PLTE 0x0008
#define PNG_INFO_tRNS 0x0010
#define PNG_INFO_bKGD 0x0020
#define PNG_INFO_hIST 0x0040
#define PNG_INFO_pHYs 0x0080
#define PNG_INFO_oFFs 0x0100
#define PNG_INFO_tIME 0x0200
#define PNG_INFO_pCAL 0x0400
#define PNG_INFO_sRGB 0x0800   /* GR-P, 0.96a */
#define PNG_INFO_iCCP 0x1000   /* ESR, 1.0.6 */
#define PNG_INFO_sPLT 0x2000   /* ESR, 1.0.6 */
#define PNG_INFO_sCAL 0x4000   /* ESR, 1.0.6 */
#define PNG_INFO_IDAT 0x8000L  /* ESR, 1.0.6 */
typedef struct png_row_info_struct
{
   png_uint_32 width;    /* width of row */
   png_size_t rowbytes;  /* number of bytes in row */
   png_byte color_type;  /* color type of row */
   png_byte bit_depth;   /* bit depth of row */
   png_byte channels;    /* number of channels (1, 2, 3, or 4) */
   png_byte pixel_depth; /* bits per pixel (depth * channels) */
} png_row_info;
typedef png_row_info FAR * png_row_infop;
typedef png_row_info FAR * FAR * png_row_infopp;
typedef struct png_struct_def png_struct;
typedef PNG_CONST png_struct FAR * png_const_structp;
typedef png_struct FAR * png_structp;
typedef PNG_CALLBACK(void, *png_error_ptr, (png_structp, png_const_charp));
typedef PNG_CALLBACK(void, *png_rw_ptr, (png_structp, png_bytep, png_size_t));
typedef PNG_CALLBACK(void, *png_flush_ptr, (png_structp));
typedef PNG_CALLBACK(void, *png_read_status_ptr, (png_structp, png_uint_32,
    int));
typedef PNG_CALLBACK(void, *png_write_status_ptr, (png_structp, png_uint_32,
    int));
#ifdef PNG_PROGRESSIVE_READ_SUPPORTED
typedef PNG_CALLBACK(void, *png_progressive_info_ptr, (png_structp, png_infop));
typedef PNG_CALLBACK(void, *png_progressive_end_ptr, (png_structp, png_infop));
typedef PNG_CALLBACK(void, *png_progressive_row_ptr, (png_structp, png_bytep,
    png_uint_32, int));
#endif
#if defined(PNG_READ_USER_TRANSFORM_SUPPORTED) || \
    defined(PNG_WRITE_USER_TRANSFORM_SUPPORTED)
typedef PNG_CALLBACK(void, *png_user_transform_ptr, (png_structp, png_row_infop,
    png_bytep));
#endif
#ifdef PNG_USER_CHUNKS_SUPPORTED
typedef PNG_CALLBACK(int, *png_user_chunk_ptr, (png_structp,
    png_unknown_chunkp));
#endif
#ifdef PNG_UNKNOWN_CHUNKS_SUPPORTED
typedef PNG_CALLBACK(void, *png_unknown_chunk_ptr, (png_structp));
#endif
#ifdef PNG_SETJMP_SUPPORTED
PNG_FUNCTION(void, (PNGCAPI *png_longjmp_ptr), PNGARG((jmp_buf, int)), typedef);
#endif
#define PNG_TRANSFORM_IDENTITY       0x0000    /* read and write */
#define PNG_TRANSFORM_STRIP_16       0x0001    /* read only */
#define PNG_TRANSFORM_STRIP_ALPHA    0x0002    /* read only */
#define PNG_TRANSFORM_PACKING        0x0004    /* read and write */
#define PNG_TRANSFORM_PACKSWAP       0x0008    /* read and write */
#define PNG_TRANSFORM_EXPAND         0x0010    /* read only */
#define PNG_TRANSFORM_INVERT_MONO    0x0020    /* read and write */
#define PNG_TRANSFORM_SHIFT          0x0040    /* read and write */
#define PNG_TRANSFORM_BGR            0x0080    /* read and write */
#define PNG_TRANSFORM_SWAP_ALPHA     0x0100    /* read and write */
#define PNG_TRANSFORM_SWAP_ENDIAN    0x0200    /* read and write */
#define PNG_TRANSFORM_INVERT_ALPHA   0x0400    /* read and write */
#define PNG_TRANSFORM_STRIP_FILLER   0x0800    /* write only */
#define PNG_TRANSFORM_STRIP_FILLER_BEFORE PNG_TRANSFORM_STRIP_FILLER
#define PNG_TRANSFORM_STRIP_FILLER_AFTER 0x1000 /* write only */
#define PNG_TRANSFORM_GRAY_TO_RGB   0x2000      /* read only */
#define PNG_TRANSFORM_EXPAND_16     0x4000      /* read only */
#define PNG_TRANSFORM_SCALE_16      0x8000      /* read only */
#define PNG_FLAG_MNG_EMPTY_PLTE     0x01
#define PNG_FLAG_MNG_FILTER_64      0x04
#define PNG_ALL_MNG_FEATURES        0x05
typedef PNG_CALLBACK(png_voidp, *png_malloc_ptr, (png_structp,
    png_alloc_size_t));
typedef PNG_CALLBACK(void, *png_free_ptr, (png_structp, png_voidp));
typedef png_struct FAR * FAR * png_structpp;
PNG_EXPORT(1, png_uint_32, png_access_version_number, (void));
PNG_EXPORT(2, void, png_set_sig_bytes, (png_structp png_ptr, int num_bytes));
PNG_EXPORT(3, int, png_sig_cmp, (png_const_bytep sig, png_size_t start,
    png_size_t num_to_check));
#define png_check_sig(sig, n) !png_sig_cmp((sig), 0, (n))
PNG_EXPORTA(4, png_structp, png_create_read_struct,
    (png_const_charp user_png_ver, png_voidp error_ptr,
    png_error_ptr error_fn, png_error_ptr warn_fn),
    PNG_ALLOCATED);
PNG_EXPORTA(5, png_structp, png_create_write_struct,
    (png_const_charp user_png_ver, png_voidp error_ptr, png_error_ptr error_fn,
    png_error_ptr warn_fn),
    PNG_ALLOCATED);

PNG_EXPORT(6, png_size_t, png_get_compression_buffer_size,
    (png_const_structp png_ptr));

PNG_EXPORT(7, void, png_set_compression_buffer_size, (png_structp png_ptr,
    png_size_t size));
#ifdef PNG_SETJMP_SUPPORTED
PNG_EXPORT(8, jmp_buf*, png_set_longjmp_fn, (png_structp png_ptr,
    png_longjmp_ptr longjmp_fn, size_t jmp_buf_size));
#  define png_jmpbuf(png_ptr) \
      (*png_set_longjmp_fn((png_ptr), longjmp, sizeof (jmp_buf)))
#else
#  define png_jmpbuf(png_ptr) \
      (LIBPNG_WAS_COMPILED_WITH__PNG_NO_SETJMP)
#endif
PNG_EXPORTA(9, void, png_longjmp, (png_structp png_ptr, int val),
    PNG_NORETURN);
#ifdef PNG_READ_SUPPORTED
PNG_EXPORT(10, int, png_reset_zstream, (png_structp png_ptr));
#endif
#ifdef PNG_USER_MEM_SUPPORTED
PNG_EXPORTA(11, png_structp, png_create_read_struct_2,
    (png_const_charp user_png_ver, png_voidp error_ptr, png_error_ptr error_fn,
    png_error_ptr warn_fn,
    png_voidp mem_ptr, png_malloc_ptr malloc_fn, png_free_ptr free_fn),
    PNG_ALLOCATED);
PNG_EXPORTA(12, png_structp, png_create_write_struct_2,
    (png_const_charp user_png_ver, png_voidp error_ptr, png_error_ptr error_fn,
    png_error_ptr warn_fn,
    png_voidp mem_ptr, png_malloc_ptr malloc_fn, png_free_ptr free_fn),
    PNG_ALLOCATED);
#endif

/* Write the PNG file signature. */
PNG_EXPORT(13, void, png_write_sig, (png_structp png_ptr));

/* Write a PNG chunk - size, type, (optional) data, CRC. */
PNG_EXPORT(14, void, png_write_chunk, (png_structp png_ptr, png_const_bytep
    chunk_name, png_const_bytep data, png_size_t length));

/* Write the start of a PNG chunk - length and chunk name. */
PNG_EXPORT(15, void, png_write_chunk_start, (png_structp png_ptr,
    png_const_bytep chunk_name, png_uint_32 length));

/* Write the data of a PNG chunk started with png_write_chunk_start(). */
PNG_EXPORT(16, void, png_write_chunk_data, (png_structp png_ptr,
    png_const_bytep data, png_size_t length));

/* Finish a chunk started with png_write_chunk_start() (includes CRC). */
PNG_EXPORT(17, void, png_write_chunk_end, (png_structp png_ptr));

/* Allocate and initialize the info structure */
PNG_EXPORTA(18, png_infop, png_create_info_struct, (png_structp png_ptr),
    PNG_ALLOCATED);

PNG_EXPORT(19, void, png_info_init_3, (png_infopp info_ptr,
    png_size_t png_info_struct_size));

/* Writes all the PNG information before the image. */
PNG_EXPORT(20, void, png_write_info_before_PLTE,
    (png_structp png_ptr, png_infop info_ptr));
PNG_EXPORT(21, void, png_write_info,
    (png_structp png_ptr, png_infop info_ptr));

#ifdef PNG_SEQUENTIAL_READ_SUPPORTED
/* Read the information before the actual image data. */
PNG_EXPORT(22, void, png_read_info,
    (png_structp png_ptr, png_infop info_ptr));
#endif

#ifdef PNG_TIME_RFC1123_SUPPORTED
PNG_EXPORT(23, png_const_charp, png_convert_to_rfc1123,
    (png_structp png_ptr,
    png_const_timep ptime));
#endif

#ifdef PNG_CONVERT_tIME_SUPPORTED
/* Convert from a struct tm to png_time */
PNG_EXPORT(24, void, png_convert_from_struct_tm, (png_timep ptime,
    PNG_CONST struct tm FAR * ttime));
PNG_EXPORT(25, void, png_convert_from_time_t,
    (png_timep ptime, time_t ttime));
#endif
#ifdef PNG_READ_EXPAND_SUPPORTED
PNG_EXPORT(26, void, png_set_expand, (png_structp png_ptr));
PNG_EXPORT(27, void, png_set_expand_gray_1_2_4_to_8, (png_structp png_ptr));
PNG_EXPORT(28, void, png_set_palette_to_rgb, (png_structp png_ptr));
PNG_EXPORT(29, void, png_set_tRNS_to_alpha, (png_structp png_ptr));
#endif
#ifdef PNG_READ_EXPAND_16_SUPPORTED
PNG_EXPORT(221, void, png_set_expand_16, (png_structp png_ptr));
#endif
#if defined(PNG_READ_BGR_SUPPORTED) || defined(PNG_WRITE_BGR_SUPPORTED)
PNG_EXPORT(30, void, png_set_bgr, (png_structp png_ptr));
#endif
#ifdef PNG_READ_GRAY_TO_RGB_SUPPORTED
PNG_EXPORT(31, void, png_set_gray_to_rgb, (png_structp png_ptr));
#endif
#ifdef PNG_READ_RGB_TO_GRAY_SUPPORTED
PNG_FP_EXPORT(32, void, png_set_rgb_to_gray, (png_structp png_ptr,
    int error_action, double red, double green));
PNG_FIXED_EXPORT(33, void, png_set_rgb_to_gray_fixed, (png_structp png_ptr,
    int error_action, png_fixed_point red, png_fixed_point green));

PNG_EXPORT(34, png_byte, png_get_rgb_to_gray_status, (png_const_structp
    png_ptr));
#endif
#ifdef PNG_BUILD_GRAYSCALE_PALETTE_SUPPORTED
PNG_EXPORT(35, void, png_build_grayscale_palette, (int bit_depth,
    png_colorp palette));
#endif
#ifdef PNG_READ_ALPHA_MODE_SUPPORTED
#define PNG_ALPHA_PNG           0 /* according to the PNG standard */
#define PNG_ALPHA_STANDARD      1 /* according to Porter/Duff */
#define PNG_ALPHA_ASSOCIATED    1 /* as above; this is the normal practice */
#define PNG_ALPHA_PREMULTIPLIED 1 /* as above */
#define PNG_ALPHA_OPTIMIZED     2 /* 'PNG' for opaque pixels, else 'STANDARD' */
#define PNG_ALPHA_BROKEN        3 /* the alpha channel is gamma encoded */

PNG_FP_EXPORT(227, void, png_set_alpha_mode, (png_structp png_ptr, int mode,
    double output_gamma));
PNG_FIXED_EXPORT(228, void, png_set_alpha_mode_fixed, (png_structp png_ptr,
    int mode, png_fixed_point output_gamma));
#endif

#if defined(PNG_READ_GAMMA_SUPPORTED) || defined(PNG_READ_ALPHA_MODE_SUPPORTED)
#define PNG_DEFAULT_sRGB -1       /* sRGB gamma and color space */
#define PNG_GAMMA_MAC_18 -2       /* Old Mac '1.8' gamma and color space */
#define PNG_GAMMA_sRGB   220000   /* Television standards--matches sRGB gamma */
#define PNG_GAMMA_LINEAR PNG_FP_1 /* Linear */
#endif

#ifdef PNG_READ_STRIP_ALPHA_SUPPORTED
PNG_EXPORT(36, void, png_set_strip_alpha, (png_structp png_ptr));
#endif

#if defined(PNG_READ_SWAP_ALPHA_SUPPORTED) || \
    defined(PNG_WRITE_SWAP_ALPHA_SUPPORTED)
PNG_EXPORT(37, void, png_set_swap_alpha, (png_structp png_ptr));
#endif

#if defined(PNG_READ_INVERT_ALPHA_SUPPORTED) || \
    defined(PNG_WRITE_INVERT_ALPHA_SUPPORTED)
PNG_EXPORT(38, void, png_set_invert_alpha, (png_structp png_ptr));
#endif

#if defined(PNG_READ_FILLER_SUPPORTED) || defined(PNG_WRITE_FILLER_SUPPORTED)
/* Add a filler byte to 8-bit Gray or 24-bit RGB images. */
PNG_EXPORT(39, void, png_set_filler, (png_structp png_ptr, png_uint_32 filler,
    int flags));
/* The values of the PNG_FILLER_ defines should NOT be changed */
#  define PNG_FILLER_BEFORE 0
#  define PNG_FILLER_AFTER 1
/* Add an alpha byte to 8-bit Gray or 24-bit RGB images. */
PNG_EXPORT(40, void, png_set_add_alpha,
    (png_structp png_ptr, png_uint_32 filler,
    int flags));
#endif /* PNG_READ_FILLER_SUPPORTED || PNG_WRITE_FILLER_SUPPORTED */

#if defined(PNG_READ_SWAP_SUPPORTED) || defined(PNG_WRITE_SWAP_SUPPORTED)
/* Swap bytes in 16-bit depth files. */
PNG_EXPORT(41, void, png_set_swap, (png_structp png_ptr));
#endif

#if defined(PNG_READ_PACK_SUPPORTED) || defined(PNG_WRITE_PACK_SUPPORTED)
/* Use 1 byte per pixel in 1, 2, or 4-bit depth files. */
PNG_EXPORT(42, void, png_set_packing, (png_structp png_ptr));
#endif

#if defined(PNG_READ_PACKSWAP_SUPPORTED) || \
    defined(PNG_WRITE_PACKSWAP_SUPPORTED)
PNG_EXPORT(43, void, png_set_packswap, (png_structp png_ptr));
#endif
#if defined(PNG_READ_SHIFT_SUPPORTED) || defined(PNG_WRITE_SHIFT_SUPPORTED)
PNG_EXPORT(44, void, png_set_shift, (png_structp png_ptr, png_const_color_8p
    true_bits));
#endif
#if defined(PNG_READ_INTERLACING_SUPPORTED) || \
    defined(PNG_WRITE_INTERLACING_SUPPORTED)
PNG_EXPORT(45, int, png_set_interlace_handling, (png_structp png_ptr));
#endif
#if defined(PNG_READ_INVERT_SUPPORTED) || defined(PNG_WRITE_INVERT_SUPPORTED)
PNG_EXPORT(46, void, png_set_invert_mono, (png_structp png_ptr));
#endif
#ifdef PNG_READ_BACKGROUND_SUPPORTED
PNG_FP_EXPORT(47, void, png_set_background, (png_structp png_ptr,
    png_const_color_16p background_color, int background_gamma_code,
    int need_expand, double background_gamma));
PNG_FIXED_EXPORT(215, void, png_set_background_fixed, (png_structp png_ptr,
    png_const_color_16p background_color, int background_gamma_code,
    int need_expand, png_fixed_point background_gamma));
#endif
#ifdef PNG_READ_BACKGROUND_SUPPORTED
#  define PNG_BACKGROUND_GAMMA_UNKNOWN 0
#  define PNG_BACKGROUND_GAMMA_SCREEN  1
#  define PNG_BACKGROUND_GAMMA_FILE    2
#  define PNG_BACKGROUND_GAMMA_UNIQUE  3
#endif
#ifdef PNG_READ_SCALE_16_TO_8_SUPPORTED
PNG_EXPORT(229, void, png_set_scale_16, (png_structp png_ptr));
#endif
#ifdef PNG_READ_STRIP_16_TO_8_SUPPORTED
#define PNG_READ_16_TO_8 SUPPORTED /* Name prior to 1.5.4 */
/* Strip the second byte of information from a 16-bit depth file. */
PNG_EXPORT(48, void, png_set_strip_16, (png_structp png_ptr));
#endif
#ifdef PNG_READ_QUANTIZE_SUPPORTED
PNG_EXPORT(49, void, png_set_quantize,
    (png_structp png_ptr, png_colorp palette,
    int num_palette, int maximum_colors, png_const_uint_16p histogram,
    int full_quantize));
#endif
#ifdef PNG_READ_GAMMA_SUPPORTED
#define PNG_GAMMA_THRESHOLD (PNG_GAMMA_THRESHOLD_FIXED*.00001)
PNG_FP_EXPORT(50, void, png_set_gamma,
    (png_structp png_ptr, double screen_gamma,
    double override_file_gamma));
PNG_FIXED_EXPORT(208, void, png_set_gamma_fixed, (png_structp png_ptr,
    png_fixed_point screen_gamma, png_fixed_point override_file_gamma));
#endif
#ifdef PNG_WRITE_FLUSH_SUPPORTED
/* Set how many lines between output flushes - 0 for no flushing */
PNG_EXPORT(51, void, png_set_flush, (png_structp png_ptr, int nrows));
/* Flush the current PNG output buffer */
PNG_EXPORT(52, void, png_write_flush, (png_structp png_ptr));
#endif

/* Optional update palette with requested transformations */
PNG_EXPORT(53, void, png_start_read_image, (png_structp png_ptr));

/* Optional call to update the users info structure */
PNG_EXPORT(54, void, png_read_update_info,
    (png_structp png_ptr, png_infop info_ptr));

#ifdef PNG_SEQUENTIAL_READ_SUPPORTED
/* Read one or more rows of image data. */
PNG_EXPORT(55, void, png_read_rows, (png_structp png_ptr, png_bytepp row,
    png_bytepp display_row, png_uint_32 num_rows));
#endif

#ifdef PNG_SEQUENTIAL_READ_SUPPORTED
/* Read a row of data. */
PNG_EXPORT(56, void, png_read_row, (png_structp png_ptr, png_bytep row,
    png_bytep display_row));
#endif

#ifdef PNG_SEQUENTIAL_READ_SUPPORTED
/* Read the whole image into memory at once. */
PNG_EXPORT(57, void, png_read_image, (png_structp png_ptr, png_bytepp image));
#endif

/* Write a row of image data */
PNG_EXPORT(58, void, png_write_row,
    (png_structp png_ptr, png_const_bytep row));
PNG_EXPORT(59, void, png_write_rows, (png_structp png_ptr, png_bytepp row,
    png_uint_32 num_rows));

/* Write the image data */
PNG_EXPORT(60, void, png_write_image,
    (png_structp png_ptr, png_bytepp image));

/* Write the end of the PNG file. */
PNG_EXPORT(61, void, png_write_end,
    (png_structp png_ptr, png_infop info_ptr));

#ifdef PNG_SEQUENTIAL_READ_SUPPORTED
/* Read the end of the PNG file. */
PNG_EXPORT(62, void, png_read_end, (png_structp png_ptr, png_infop info_ptr));
#endif

/* Free any memory associated with the png_info_struct */
PNG_EXPORT(63, void, png_destroy_info_struct, (png_structp png_ptr,
    png_infopp info_ptr_ptr));

/* Free any memory associated with the png_struct and the png_info_structs */
PNG_EXPORT(64, void, png_destroy_read_struct, (png_structpp png_ptr_ptr,
    png_infopp info_ptr_ptr, png_infopp end_info_ptr_ptr));

/* Free any memory associated with the png_struct and the png_info_structs */
PNG_EXPORT(65, void, png_destroy_write_struct, (png_structpp png_ptr_ptr,
    png_infopp info_ptr_ptr));

/* Set the libpng method of handling chunk CRC errors */
PNG_EXPORT(66, void, png_set_crc_action,
    (png_structp png_ptr, int crit_action, int ancil_action));
#define PNG_CRC_DEFAULT       0  /* error/quit          warn/discard data */
#define PNG_CRC_ERROR_QUIT    1  /* error/quit          error/quit        */
#define PNG_CRC_WARN_DISCARD  2  /* (INVALID)           warn/discard data */
#define PNG_CRC_WARN_USE      3  /* warn/use data       warn/use data     */
#define PNG_CRC_QUIET_USE     4  /* quiet/use data      quiet/use data    */
#define PNG_CRC_NO_CHANGE     5  /* use current value   use current value */
PNG_EXPORT(67, void, png_set_filter,
    (png_structp png_ptr, int method, int filters));
#define PNG_NO_FILTERS     0x00
#define PNG_FILTER_NONE    0x08
#define PNG_FILTER_SUB     0x10
#define PNG_FILTER_UP      0x20
#define PNG_FILTER_AVG     0x40
#define PNG_FILTER_PAETH   0x80
#define PNG_ALL_FILTERS (PNG_FILTER_NONE | PNG_FILTER_SUB | PNG_FILTER_UP | \
                         PNG_FILTER_AVG | PNG_FILTER_PAETH)
#define PNG_FILTER_VALUE_NONE  0
#define PNG_FILTER_VALUE_SUB   1
#define PNG_FILTER_VALUE_UP    2
#define PNG_FILTER_VALUE_AVG   3
#define PNG_FILTER_VALUE_PAETH 4
#define PNG_FILTER_VALUE_LAST  5

#ifdef PNG_WRITE_WEIGHTED_FILTER_SUPPORTED /* EXPERIMENTAL */
PNG_FP_EXPORT(68, void, png_set_filter_heuristics, (png_structp png_ptr,
    int heuristic_method, int num_weights, png_const_doublep filter_weights,
    png_const_doublep filter_costs));
PNG_FIXED_EXPORT(209, void, png_set_filter_heuristics_fixed,
    (png_structp png_ptr,
    int heuristic_method, int num_weights, png_const_fixed_point_p
    filter_weights, png_const_fixed_point_p filter_costs));
#endif
#define PNG_FILTER_HEURISTIC_DEFAULT    0  /* Currently "UNWEIGHTED" */
#define PNG_FILTER_HEURISTIC_UNWEIGHTED 1  /* Used by libpng < 0.95 */
#define PNG_FILTER_HEURISTIC_WEIGHTED   2  /* Experimental feature */
#define PNG_FILTER_HEURISTIC_LAST       3  /* Not a valid value */

#ifdef PNG_WRITE_SUPPORTED
PNG_EXPORT(69, void, png_set_compression_level,
    (png_structp png_ptr, int level));

PNG_EXPORT(70, void, png_set_compression_mem_level, (png_structp png_ptr,
    int mem_level));

PNG_EXPORT(71, void, png_set_compression_strategy, (png_structp png_ptr,
    int strategy));
PNG_EXPORT(72, void, png_set_compression_window_bits, (png_structp png_ptr,
    int window_bits));

PNG_EXPORT(73, void, png_set_compression_method, (png_structp png_ptr,
    int method));
#endif

#ifdef PNG_WRITE_CUSTOMIZE_ZTXT_COMPRESSION_SUPPORTED
/* Also set zlib parameters for compressing non-IDAT chunks */
PNG_EXPORT(222, void, png_set_text_compression_level,
    (png_structp png_ptr, int level));

PNG_EXPORT(223, void, png_set_text_compression_mem_level, (png_structp png_ptr,
    int mem_level));

PNG_EXPORT(224, void, png_set_text_compression_strategy, (png_structp png_ptr,
    int strategy));

/* If PNG_WRITE_OPTIMIZE_CMF_SUPPORTED is defined, libpng will use a
 * smaller value of window_bits if it can do so safely.
 */
PNG_EXPORT(225, void, png_set_text_compression_window_bits, (png_structp
    png_ptr, int window_bits));

PNG_EXPORT(226, void, png_set_text_compression_method, (png_structp png_ptr,
    int method));
#endif
#ifdef PNG_STDIO_SUPPORTED
/* Initialize the input/output for the PNG file to the default functions. */
PNG_EXPORT(74, void, png_init_io, (png_structp png_ptr, png_FILE_p fp));
#endif
PNG_EXPORT(75, void, png_set_error_fn,
    (png_structp png_ptr, png_voidp error_ptr,
    png_error_ptr error_fn, png_error_ptr warning_fn));

/* Return the user pointer associated with the error functions */
PNG_EXPORT(76, png_voidp, png_get_error_ptr, (png_const_structp png_ptr));
PNG_EXPORT(77, void, png_set_write_fn, (png_structp png_ptr, png_voidp io_ptr,
    png_rw_ptr write_data_fn, png_flush_ptr output_flush_fn));

/* Replace the default data input function with a user supplied one. */
PNG_EXPORT(78, void, png_set_read_fn, (png_structp png_ptr, png_voidp io_ptr,
    png_rw_ptr read_data_fn));

/* Return the user pointer associated with the I/O functions */
PNG_EXPORT(79, png_voidp, png_get_io_ptr, (png_structp png_ptr));

PNG_EXPORT(80, void, png_set_read_status_fn, (png_structp png_ptr,
    png_read_status_ptr read_row_fn));

PNG_EXPORT(81, void, png_set_write_status_fn, (png_structp png_ptr,
    png_write_status_ptr write_row_fn));

#ifdef PNG_USER_MEM_SUPPORTED
/* Replace the default memory allocation functions with user supplied one(s). */
PNG_EXPORT(82, void, png_set_mem_fn, (png_structp png_ptr, png_voidp mem_ptr,
    png_malloc_ptr malloc_fn, png_free_ptr free_fn));
/* Return the user pointer associated with the memory functions */
PNG_EXPORT(83, png_voidp, png_get_mem_ptr, (png_const_structp png_ptr));
#endif

#ifdef PNG_READ_USER_TRANSFORM_SUPPORTED
PNG_EXPORT(84, void, png_set_read_user_transform_fn, (png_structp png_ptr,
    png_user_transform_ptr read_user_transform_fn));
#endif

#ifdef PNG_WRITE_USER_TRANSFORM_SUPPORTED
PNG_EXPORT(85, void, png_set_write_user_transform_fn, (png_structp png_ptr,
    png_user_transform_ptr write_user_transform_fn));
#endif

#ifdef PNG_USER_TRANSFORM_PTR_SUPPORTED
PNG_EXPORT(86, void, png_set_user_transform_info, (png_structp png_ptr,
    png_voidp user_transform_ptr, int user_transform_depth,
    int user_transform_channels));
PNG_EXPORT(87, png_voidp, png_get_user_transform_ptr,
    (png_const_structp png_ptr));
#endif

#ifdef PNG_USER_TRANSFORM_INFO_SUPPORTED
PNG_EXPORT(217, png_uint_32, png_get_current_row_number, (png_const_structp));
PNG_EXPORT(218, png_byte, png_get_current_pass_number, (png_const_structp));
#endif

#ifdef PNG_USER_CHUNKS_SUPPORTED
PNG_EXPORT(88, void, png_set_read_user_chunk_fn, (png_structp png_ptr,
    png_voidp user_chunk_ptr, png_user_chunk_ptr read_user_chunk_fn));
PNG_EXPORT(89, png_voidp, png_get_user_chunk_ptr, (png_const_structp png_ptr));
#endif

#ifdef PNG_PROGRESSIVE_READ_SUPPORTED
PNG_EXPORT(90, void, png_set_progressive_read_fn, (png_structp png_ptr,
    png_voidp progressive_ptr, png_progressive_info_ptr info_fn,
    png_progressive_row_ptr row_fn, png_progressive_end_ptr end_fn));

/* Returns the user pointer associated with the push read functions */
PNG_EXPORT(91, png_voidp, png_get_progressive_ptr, (png_const_structp png_ptr));

/* Function to be called when data becomes available */
PNG_EXPORT(92, void, png_process_data,
    (png_structp png_ptr, png_infop info_ptr,
    png_bytep buffer, png_size_t buffer_size));
PNG_EXPORT(219, png_size_t, png_process_data_pause, (png_structp, int save));
PNG_EXPORT(220, png_uint_32, png_process_data_skip, (png_structp));
PNG_EXPORT(93, void, png_progressive_combine_row, (png_structp png_ptr,
    png_bytep old_row, png_const_bytep new_row));
#endif /* PNG_PROGRESSIVE_READ_SUPPORTED */

PNG_EXPORTA(94, png_voidp, png_malloc,
    (png_structp png_ptr, png_alloc_size_t size),
    PNG_ALLOCATED);
/* Added at libpng version 1.4.0 */
PNG_EXPORTA(95, png_voidp, png_calloc,
    (png_structp png_ptr, png_alloc_size_t size),
    PNG_ALLOCATED);

/* Added at libpng version 1.2.4 */
PNG_EXPORTA(96, png_voidp, png_malloc_warn, (png_structp png_ptr,
    png_alloc_size_t size), PNG_ALLOCATED);

/* Frees a pointer allocated by png_malloc() */
PNG_EXPORT(97, void, png_free, (png_structp png_ptr, png_voidp ptr));

/* Free data that was allocated internally */
PNG_EXPORT(98, void, png_free_data,
    (png_structp png_ptr, png_infop info_ptr, png_uint_32 free_me, int num));

/* Reassign responsibility for freeing existing data, whether allocated
 * by libpng or by the application */
PNG_EXPORT(99, void, png_data_freer,
    (png_structp png_ptr, png_infop info_ptr, int freer, png_uint_32 mask));

/* Assignments for png_data_freer */
#define PNG_DESTROY_WILL_FREE_DATA 1
#define PNG_SET_WILL_FREE_DATA 1
#define PNG_USER_WILL_FREE_DATA 2
/* Flags for png_ptr->free_me and info_ptr->free_me */
#define PNG_FREE_HIST 0x0008
#define PNG_FREE_ICCP 0x0010
#define PNG_FREE_SPLT 0x0020
#define PNG_FREE_ROWS 0x0040
#define PNG_FREE_PCAL 0x0080
#define PNG_FREE_SCAL 0x0100
#define PNG_FREE_UNKN 0x0200
#define PNG_FREE_LIST 0x0400
#define PNG_FREE_PLTE 0x1000
#define PNG_FREE_TRNS 0x2000
#define PNG_FREE_TEXT 0x4000
#define PNG_FREE_ALL  0x7fff
#define PNG_FREE_MUL  0x4220 /* PNG_FREE_SPLT|PNG_FREE_TEXT|PNG_FREE_UNKN */

#ifdef PNG_USER_MEM_SUPPORTED
PNG_EXPORTA(100, png_voidp, png_malloc_default, (png_structp png_ptr,
    png_alloc_size_t size), PNG_ALLOCATED);
PNG_EXPORT(101, void, png_free_default, (png_structp png_ptr, png_voidp ptr));
#endif

#ifdef PNG_ERROR_TEXT_SUPPORTED
/* Fatal error in PNG image of libpng - can't continue */
PNG_EXPORTA(102, void, png_error,
    (png_structp png_ptr, png_const_charp error_message),
    PNG_NORETURN);

/* The same, but the chunk name is prepended to the error string. */
PNG_EXPORTA(103, void, png_chunk_error, (png_structp png_ptr,
    png_const_charp error_message), PNG_NORETURN);

#else
/* Fatal error in PNG image of libpng - can't continue */
PNG_EXPORTA(104, void, png_err, (png_structp png_ptr), PNG_NORETURN);
#endif

#ifdef PNG_WARNINGS_SUPPORTED
/* Non-fatal error in libpng.  Can continue, but may have a problem. */
PNG_EXPORT(105, void, png_warning, (png_structp png_ptr,
    png_const_charp warning_message));
PNG_EXPORT(106, void, png_chunk_warning, (png_structp png_ptr,
    png_const_charp warning_message));
#endif
#ifdef PNG_BENIGN_ERRORS_SUPPORTED
#  undef png_benign_error
PNG_EXPORT(107, void, png_benign_error, (png_structp png_ptr,
    png_const_charp warning_message));
#  undef png_chunk_benign_error
PNG_EXPORT(108, void, png_chunk_benign_error, (png_structp png_ptr,
    png_const_charp warning_message));

PNG_EXPORT(109, void, png_set_benign_errors,
    (png_structp png_ptr, int allowed));
#else
#  ifdef PNG_ALLOW_BENIGN_ERRORS
#    define png_benign_error png_warning
#    define png_chunk_benign_error png_chunk_warning
#  else
#    define png_benign_error png_error
#    define png_chunk_benign_error png_chunk_error
#  endif
#endif
PNG_EXPORT(110, png_uint_32, png_get_valid,
    (png_const_structp png_ptr, png_const_infop info_ptr,
    png_uint_32 flag));
PNG_EXPORT(111, png_size_t, png_get_rowbytes, (png_const_structp png_ptr,
    png_const_infop info_ptr));
#ifdef PNG_INFO_IMAGE_SUPPORTED
PNG_EXPORT(112, png_bytepp, png_get_rows,
    (png_const_structp png_ptr, png_const_infop info_ptr));
PNG_EXPORT(113, void, png_set_rows, (png_structp png_ptr,
    png_infop info_ptr, png_bytepp row_pointers));
#endif
PNG_EXPORT(114, png_byte, png_get_channels,
    (png_const_structp png_ptr, png_const_infop info_ptr));
#ifdef PNG_EASY_ACCESS_SUPPORTED
PNG_EXPORT(115, png_uint_32, png_get_image_width, (png_const_structp png_ptr,
    png_const_infop info_ptr));
PNG_EXPORT(116, png_uint_32, png_get_image_height, (png_const_structp png_ptr,
    png_const_infop info_ptr));
PNG_EXPORT(117, png_byte, png_get_bit_depth,
    (png_const_structp png_ptr, png_const_infop info_ptr));
PNG_EXPORT(118, png_byte, png_get_color_type, (png_const_structp png_ptr,
    png_const_infop info_ptr));
PNG_EXPORT(119, png_byte, png_get_filter_type, (png_const_structp png_ptr,
    png_const_infop info_ptr));
PNG_EXPORT(120, png_byte, png_get_interlace_type, (png_const_structp png_ptr,
    png_const_infop info_ptr));
PNG_EXPORT(121, png_byte, png_get_compression_type, (png_const_structp png_ptr,
    png_const_infop info_ptr));
PNG_EXPORT(122, png_uint_32, png_get_pixels_per_meter,
    (png_const_structp png_ptr, png_const_infop info_ptr));
PNG_EXPORT(123, png_uint_32, png_get_x_pixels_per_meter,
    (png_const_structp png_ptr, png_const_infop info_ptr));
PNG_EXPORT(124, png_uint_32, png_get_y_pixels_per_meter,
    (png_const_structp png_ptr, png_const_infop info_ptr));
PNG_FP_EXPORT(125, float, png_get_pixel_aspect_ratio,
    (png_const_structp png_ptr, png_const_infop info_ptr));
PNG_FIXED_EXPORT(210, png_fixed_point, png_get_pixel_aspect_ratio_fixed,
    (png_const_structp png_ptr, png_const_infop info_ptr));
PNG_EXPORT(126, png_int_32, png_get_x_offset_pixels,
    (png_const_structp png_ptr, png_const_infop info_ptr));
PNG_EXPORT(127, png_int_32, png_get_y_offset_pixels,
    (png_const_structp png_ptr, png_const_infop info_ptr));
PNG_EXPORT(128, png_int_32, png_get_x_offset_microns,
    (png_const_structp png_ptr, png_const_infop info_ptr));
PNG_EXPORT(129, png_int_32, png_get_y_offset_microns,
    (png_const_structp png_ptr, png_const_infop info_ptr));

#endif
PNG_EXPORT(130, png_const_bytep, png_get_signature,
    (png_const_structp png_ptr, png_infop info_ptr));
#ifdef PNG_bKGD_SUPPORTED
PNG_EXPORT(131, png_uint_32, png_get_bKGD,
    (png_const_structp png_ptr, png_infop info_ptr,
    png_color_16p *background));
#endif
#ifdef PNG_bKGD_SUPPORTED
PNG_EXPORT(132, void, png_set_bKGD, (png_structp png_ptr, png_infop info_ptr,
    png_const_color_16p background));
#endif
#ifdef PNG_cHRM_SUPPORTED
PNG_FP_EXPORT(133, png_uint_32, png_get_cHRM, (png_const_structp png_ptr,
   png_const_infop info_ptr, double *white_x, double *white_y, double *red_x,
    double *red_y, double *green_x, double *green_y, double *blue_x,
    double *blue_y));
#ifdef PNG_FIXED_POINT_SUPPORTED
PNG_FIXED_EXPORT(134, png_uint_32, png_get_cHRM_fixed,
    (png_const_structp png_ptr,
    png_const_infop info_ptr, png_fixed_point *int_white_x,
    png_fixed_point *int_white_y, png_fixed_point *int_red_x,
    png_fixed_point *int_red_y, png_fixed_point *int_green_x,
    png_fixed_point *int_green_y, png_fixed_point *int_blue_x,
    png_fixed_point *int_blue_y));
#endif
#endif
#ifdef PNG_cHRM_SUPPORTED
PNG_FP_EXPORT(135, void, png_set_cHRM,
    (png_structp png_ptr, png_infop info_ptr,
    double white_x, double white_y, double red_x, double red_y, double green_x,
    double green_y, double blue_x, double blue_y));
PNG_FIXED_EXPORT(136, void, png_set_cHRM_fixed, (png_structp png_ptr,
    png_infop info_ptr, png_fixed_point int_white_x,
    png_fixed_point int_white_y, png_fixed_point int_red_x,
    png_fixed_point int_red_y, png_fixed_point int_green_x,
    png_fixed_point int_green_y, png_fixed_point int_blue_x,
    png_fixed_point int_blue_y));
#endif
#ifdef PNG_gAMA_SUPPORTED
PNG_FP_EXPORT(137, png_uint_32, png_get_gAMA,
    (png_const_structp png_ptr, png_const_infop info_ptr,
    double *file_gamma));
PNG_FIXED_EXPORT(138, png_uint_32, png_get_gAMA_fixed,
    (png_const_structp png_ptr, png_const_infop info_ptr,
    png_fixed_point *int_file_gamma));
#endif
#ifdef PNG_gAMA_SUPPORTED
PNG_FP_EXPORT(139, void, png_set_gAMA, (png_structp png_ptr,
    png_infop info_ptr, double file_gamma));
PNG_FIXED_EXPORT(140, void, png_set_gAMA_fixed, (png_structp png_ptr,
    png_infop info_ptr, png_fixed_point int_file_gamma));
#endif
#ifdef PNG_hIST_SUPPORTED
PNG_EXPORT(141, png_uint_32, png_get_hIST,
    (png_const_structp png_ptr, png_const_infop info_ptr,
    png_uint_16p *hist));
#endif
#ifdef PNG_hIST_SUPPORTED
PNG_EXPORT(142, void, png_set_hIST, (png_structp png_ptr,
    png_infop info_ptr, png_const_uint_16p hist));
#endif
PNG_EXPORT(143, png_uint_32, png_get_IHDR,
    (png_structp png_ptr, png_infop info_ptr,
    png_uint_32 *width, png_uint_32 *height, int *bit_depth, int *color_type,
    int *interlace_method, int *compression_method, int *filter_method));
PNG_EXPORT(144, void, png_set_IHDR,
    (png_structp png_ptr, png_infop info_ptr,
    png_uint_32 width, png_uint_32 height, int bit_depth, int color_type,
    int interlace_method, int compression_method, int filter_method));
#ifdef PNG_oFFs_SUPPORTED
PNG_EXPORT(145, png_uint_32, png_get_oFFs,
    (png_const_structp png_ptr, png_const_infop info_ptr,
    png_int_32 *offset_x, png_int_32 *offset_y, int *unit_type));
#endif
#ifdef PNG_oFFs_SUPPORTED
PNG_EXPORT(146, void, png_set_oFFs,
    (png_structp png_ptr, png_infop info_ptr,
    png_int_32 offset_x, png_int_32 offset_y, int unit_type));
#endif
#ifdef PNG_pCAL_SUPPORTED
PNG_EXPORT(147, png_uint_32, png_get_pCAL,
    (png_const_structp png_ptr, png_const_infop info_ptr,
    png_charp *purpose, png_int_32 *X0, png_int_32 *X1, int *type,
    int *nparams,
    png_charp *units, png_charpp *params));
#endif
#ifdef PNG_pCAL_SUPPORTED
PNG_EXPORT(148, void, png_set_pCAL, (png_structp png_ptr,
    png_infop info_ptr,
    png_const_charp purpose, png_int_32 X0, png_int_32 X1, int type,
    int nparams, png_const_charp units, png_charpp params));
#endif
#ifdef PNG_pHYs_SUPPORTED
PNG_EXPORT(149, png_uint_32, png_get_pHYs,
    (png_const_structp png_ptr, png_const_infop info_ptr,
    png_uint_32 *res_x, png_uint_32 *res_y, int *unit_type));
#endif
#ifdef PNG_pHYs_SUPPORTED
PNG_EXPORT(150, void, png_set_pHYs,
    (png_structp png_ptr, png_infop info_ptr,
    png_uint_32 res_x, png_uint_32 res_y, int unit_type));
#endif
PNG_EXPORT(151, png_uint_32, png_get_PLTE,
    (png_const_structp png_ptr, png_const_infop info_ptr,
    png_colorp *palette, int *num_palette));
PNG_EXPORT(152, void, png_set_PLTE,
    (png_structp png_ptr, png_infop info_ptr,
    png_const_colorp palette, int num_palette));
#ifdef PNG_sBIT_SUPPORTED
PNG_EXPORT(153, png_uint_32, png_get_sBIT,
    (png_const_structp png_ptr, png_infop info_ptr,
    png_color_8p *sig_bit));
#endif
#ifdef PNG_sBIT_SUPPORTED
PNG_EXPORT(154, void, png_set_sBIT,
    (png_structp png_ptr, png_infop info_ptr, png_const_color_8p sig_bit));
#endif
#ifdef PNG_sRGB_SUPPORTED
PNG_EXPORT(155, png_uint_32, png_get_sRGB, (png_const_structp png_ptr,
    png_const_infop info_ptr, int *file_srgb_intent));
#endif
#ifdef PNG_sRGB_SUPPORTED
PNG_EXPORT(156, void, png_set_sRGB,
    (png_structp png_ptr, png_infop info_ptr, int srgb_intent));
PNG_EXPORT(157, void, png_set_sRGB_gAMA_and_cHRM, (png_structp png_ptr,
    png_infop info_ptr, int srgb_intent));
#endif
#ifdef PNG_iCCP_SUPPORTED
PNG_EXPORT(158, png_uint_32, png_get_iCCP,
    (png_const_structp png_ptr, png_const_infop info_ptr,
    png_charpp name, int *compression_type, png_bytepp profile,
    png_uint_32 *proflen));
#endif
#ifdef PNG_iCCP_SUPPORTED
PNG_EXPORT(159, void, png_set_iCCP,
    (png_structp png_ptr, png_infop info_ptr,
    png_const_charp name, int compression_type, png_const_bytep profile,
    png_uint_32 proflen));
#endif
#ifdef PNG_sPLT_SUPPORTED
PNG_EXPORT(160, png_uint_32, png_get_sPLT,
    (png_const_structp png_ptr, png_const_infop info_ptr,
    png_sPLT_tpp entries));
#endif
#ifdef PNG_sPLT_SUPPORTED
PNG_EXPORT(161, void, png_set_sPLT,
    (png_structp png_ptr, png_infop info_ptr,
    png_const_sPLT_tp entries, int nentries));
#endif
#ifdef PNG_TEXT_SUPPORTED
PNG_EXPORT(162, png_uint_32, png_get_text,
    (png_const_structp png_ptr, png_const_infop info_ptr,
    png_textp *text_ptr, int *num_text));
#endif
#ifdef PNG_TEXT_SUPPORTED
PNG_EXPORT(163, void, png_set_text,
    (png_structp png_ptr, png_infop info_ptr,
    png_const_textp text_ptr, int num_text));
#endif
#ifdef PNG_tIME_SUPPORTED
PNG_EXPORT(164, png_uint_32, png_get_tIME,
    (png_const_structp png_ptr, png_infop info_ptr, png_timep *mod_time));
#endif
#ifdef PNG_tIME_SUPPORTED
PNG_EXPORT(165, void, png_set_tIME,
    (png_structp png_ptr, png_infop info_ptr, png_const_timep mod_time));
#endif
#ifdef PNG_tRNS_SUPPORTED
PNG_EXPORT(166, png_uint_32, png_get_tRNS,
    (png_const_structp png_ptr, png_infop info_ptr,
    png_bytep *trans_alpha, int *num_trans, png_color_16p *trans_color));
#endif
#ifdef PNG_tRNS_SUPPORTED
PNG_EXPORT(167, void, png_set_tRNS,
    (png_structp png_ptr, png_infop info_ptr,
    png_const_bytep trans_alpha, int num_trans,
    png_const_color_16p trans_color));
#endif
#ifdef PNG_sCAL_SUPPORTED
PNG_FP_EXPORT(168, png_uint_32, png_get_sCAL,
    (png_const_structp png_ptr, png_const_infop info_ptr,
    int *unit, double *width, double *height));
#ifdef PNG_FLOATING_ARITHMETIC_SUPPORTED
PNG_FIXED_EXPORT(214, png_uint_32, png_get_sCAL_fixed,
    (png_structp png_ptr, png_const_infop info_ptr, int *unit,
    png_fixed_point *width,
    png_fixed_point *height));
#endif
PNG_EXPORT(169, png_uint_32, png_get_sCAL_s,
    (png_const_structp png_ptr, png_const_infop info_ptr,
    int *unit, png_charpp swidth, png_charpp sheight));
PNG_FP_EXPORT(170, void, png_set_sCAL,
    (png_structp png_ptr, png_infop info_ptr,
    int unit, double width, double height));
PNG_FIXED_EXPORT(213, void, png_set_sCAL_fixed, (png_structp png_ptr,
   png_infop info_ptr, int unit, png_fixed_point width,
   png_fixed_point height));
PNG_EXPORT(171, void, png_set_sCAL_s,
    (png_structp png_ptr, png_infop info_ptr,
    int unit, png_const_charp swidth, png_const_charp sheight));
#endif
#ifdef PNG_HANDLE_AS_UNKNOWN_SUPPORTED
PNG_EXPORT(172, void, png_set_keep_unknown_chunks,
    (png_structp png_ptr, int keep,
    png_const_bytep chunk_list, int num_chunks));
PNG_EXPORT(173, int, png_handle_as_unknown, (png_structp png_ptr,
    png_const_bytep chunk_name));
#endif
#ifdef PNG_UNKNOWN_CHUNKS_SUPPORTED
PNG_EXPORT(174, void, png_set_unknown_chunks, (png_structp png_ptr,
    png_infop info_ptr, png_const_unknown_chunkp unknowns,
    int num_unknowns));
PNG_EXPORT(175, void, png_set_unknown_chunk_location,
    (png_structp png_ptr, png_infop info_ptr, int chunk, int location));
PNG_EXPORT(176, int, png_get_unknown_chunks, (png_const_structp png_ptr,
    png_const_infop info_ptr, png_unknown_chunkpp entries));
#endif
PNG_EXPORT(177, void, png_set_invalid,
    (png_structp png_ptr, png_infop info_ptr, int mask));
#ifdef PNG_INFO_IMAGE_SUPPORTED
PNG_EXPORT(178, void, png_read_png, (png_structp png_ptr, png_infop info_ptr,
    int transforms, png_voidp params));
PNG_EXPORT(179, void, png_write_png, (png_structp png_ptr, png_infop info_ptr,
    int transforms, png_voidp params));
#endif
PNG_EXPORT(180, png_const_charp, png_get_copyright,
    (png_const_structp png_ptr));
PNG_EXPORT(181, png_const_charp, png_get_header_ver,
    (png_const_structp png_ptr));
PNG_EXPORT(182, png_const_charp, png_get_header_version,
    (png_const_structp png_ptr));
PNG_EXPORT(183, png_const_charp, png_get_libpng_ver,
    (png_const_structp png_ptr));
#ifdef PNG_MNG_FEATURES_SUPPORTED
PNG_EXPORT(184, png_uint_32, png_permit_mng_features, (png_structp png_ptr,
    png_uint_32 mng_features_permitted));
#endif
#define PNG_HANDLE_CHUNK_AS_DEFAULT   0
#define PNG_HANDLE_CHUNK_NEVER        1
#define PNG_HANDLE_CHUNK_IF_SAFE      2
#define PNG_HANDLE_CHUNK_ALWAYS       3
#ifdef PNG_ERROR_NUMBERS_SUPPORTED
PNG_EXPORT(185, void, png_set_strip_error_numbers,
    (png_structp png_ptr,
    png_uint_32 strip_mode));
#endif
#ifdef PNG_SET_USER_LIMITS_SUPPORTED
PNG_EXPORT(186, void, png_set_user_limits, (png_structp png_ptr,
    png_uint_32 user_width_max, png_uint_32 user_height_max));
PNG_EXPORT(187, png_uint_32, png_get_user_width_max,
    (png_const_structp png_ptr));
PNG_EXPORT(188, png_uint_32, png_get_user_height_max,
    (png_const_structp png_ptr));
/* Added in libpng-1.4.0 */
PNG_EXPORT(189, void, png_set_chunk_cache_max, (png_structp png_ptr,
    png_uint_32 user_chunk_cache_max));
PNG_EXPORT(190, png_uint_32, png_get_chunk_cache_max,
    (png_const_structp png_ptr));
/* Added in libpng-1.4.1 */
PNG_EXPORT(191, void, png_set_chunk_malloc_max, (png_structp png_ptr,
    png_alloc_size_t user_chunk_cache_max));
PNG_EXPORT(192, png_alloc_size_t, png_get_chunk_malloc_max,
    (png_const_structp png_ptr));
#endif

#if defined(PNG_INCH_CONVERSIONS_SUPPORTED)
PNG_EXPORT(193, png_uint_32, png_get_pixels_per_inch,
    (png_const_structp png_ptr, png_const_infop info_ptr));

PNG_EXPORT(194, png_uint_32, png_get_x_pixels_per_inch,
    (png_const_structp png_ptr, png_const_infop info_ptr));

PNG_EXPORT(195, png_uint_32, png_get_y_pixels_per_inch,
    (png_const_structp png_ptr, png_const_infop info_ptr));

PNG_FP_EXPORT(196, float, png_get_x_offset_inches,
    (png_const_structp png_ptr, png_const_infop info_ptr));
#ifdef PNG_FIXED_POINT_SUPPORTED /* otherwise not implemented. */
PNG_FIXED_EXPORT(211, png_fixed_point, png_get_x_offset_inches_fixed,
    (png_structp png_ptr, png_const_infop info_ptr));
#endif

PNG_FP_EXPORT(197, float, png_get_y_offset_inches, (png_const_structp png_ptr,
    png_const_infop info_ptr));
#ifdef PNG_FIXED_POINT_SUPPORTED /* otherwise not implemented. */
PNG_FIXED_EXPORT(212, png_fixed_point, png_get_y_offset_inches_fixed,
    (png_structp png_ptr, png_const_infop info_ptr));
#endif

#  ifdef PNG_pHYs_SUPPORTED
PNG_EXPORT(198, png_uint_32, png_get_pHYs_dpi, (png_const_structp png_ptr,
    png_const_infop info_ptr, png_uint_32 *res_x, png_uint_32 *res_y,
    int *unit_type));
#  endif
#endif
#ifdef PNG_IO_STATE_SUPPORTED
PNG_EXPORT(199, png_uint_32, png_get_io_state, (png_structp png_ptr));
PNG_EXPORTA(200, png_const_bytep, png_get_io_chunk_name,
    (png_structp png_ptr), PNG_DEPRECATED);
PNG_EXPORT(216, png_uint_32, png_get_io_chunk_type,
    (png_const_structp png_ptr));
#  define PNG_IO_NONE        0x0000   /* no I/O at this moment */
#  define PNG_IO_READING     0x0001   /* currently reading */
#  define PNG_IO_WRITING     0x0002   /* currently writing */
#  define PNG_IO_SIGNATURE   0x0010   /* currently at the file signature */
#  define PNG_IO_CHUNK_HDR   0x0020   /* currently at the chunk header */
#  define PNG_IO_CHUNK_DATA  0x0040   /* currently at the chunk data */
#  define PNG_IO_CHUNK_CRC   0x0080   /* currently at the chunk crc */
#  define PNG_IO_MASK_OP     0x000f   /* current operation: reading/writing */
#  define PNG_IO_MASK_LOC    0x00f0   /* current location: sig/hdr/data/crc */
#endif
#define PNG_INTERLACE_ADAM7_PASSES 7
#define PNG_PASS_START_ROW(pass) (((1U&~(pass))<<(3-((pass)>>1)))&7)
#define PNG_PASS_START_COL(pass) (((1U& (pass))<<(3-(((pass)+1)>>1)))&7)
#define PNG_PASS_ROW_SHIFT(pass) ((pass)>2?(8-(pass))>>1:3)
#define PNG_PASS_COL_SHIFT(pass) ((pass)>1?(7-(pass))>>1:3)
#define PNG_PASS_ROWS(height, pass) (((height)+(((1<<PNG_PASS_ROW_SHIFT(pass))\
   -1)-PNG_PASS_START_ROW(pass)))>>PNG_PASS_ROW_SHIFT(pass))
#define PNG_PASS_COLS(width, pass) (((width)+(((1<<PNG_PASS_COL_SHIFT(pass))\
   -1)-PNG_PASS_START_COL(pass)))>>PNG_PASS_COL_SHIFT(pass))
#define PNG_ROW_FROM_PASS_ROW(yIn, pass) \
   (((yIn)<<PNG_PASS_ROW_SHIFT(pass))+PNG_PASS_START_ROW(pass))
#define PNG_COL_FROM_PASS_COL(xIn, pass) \
   (((xIn)<<PNG_PASS_COL_SHIFT(pass))+PNG_PASS_START_COL(pass))
#define PNG_PASS_MASK(pass,off) ( \
   ((0x110145AFU>>(((7-(off))-(pass))<<2)) & 0xFU) | \
   ((0x01145AF0U>>(((7-(off))-(pass))<<2)) & 0xF0U))
#define PNG_ROW_IN_INTERLACE_PASS(y, pass) \
   ((PNG_PASS_MASK(pass,0) >> ((y)&7)) & 1)
#define PNG_COL_IN_INTERLACE_PASS(x, pass) \
   ((PNG_PASS_MASK(pass,1) >> ((x)&7)) & 1)
#ifdef PNG_READ_COMPOSITE_NODIV_SUPPORTED
#  define png_composite(composite, fg, alpha, bg)         \
     { png_uint_16 temp = (png_uint_16)((png_uint_16)(fg) \
           * (png_uint_16)(alpha)                         \
           + (png_uint_16)(bg)*(png_uint_16)(255          \
           - (png_uint_16)(alpha)) + (png_uint_16)128);   \
       (composite) = (png_byte)((temp + (temp >> 8)) >> 8); }

#  define png_composite_16(composite, fg, alpha, bg)       \
     { png_uint_32 temp = (png_uint_32)((png_uint_32)(fg)  \
           * (png_uint_32)(alpha)                          \
           + (png_uint_32)(bg)*(png_uint_32)(65535L        \
           - (png_uint_32)(alpha)) + (png_uint_32)32768L); \
       (composite) = (png_uint_16)((temp + (temp >> 16)) >> 16); }
#else
#  define png_composite(composite, fg, alpha, bg)                          \
     (composite) = (png_byte)(((png_uint_16)(fg) * (png_uint_16)(alpha) +  \
     (png_uint_16)(bg) * (png_uint_16)(255 - (png_uint_16)(alpha)) +       \
     (png_uint_16)127) / 255)
#  define png_composite_16(composite, fg, alpha, bg)                         \
     (composite) = (png_uint_16)(((png_uint_32)(fg) * (png_uint_32)(alpha) + \
     (png_uint_32)(bg)*(png_uint_32)(65535L - (png_uint_32)(alpha)) +        \
     (png_uint_32)32767) / (png_uint_32)65535L)
#endif
#ifdef PNG_READ_INT_FUNCTIONS_SUPPORTED
PNG_EXPORT(201, png_uint_32, png_get_uint_32, (png_const_bytep buf));
PNG_EXPORT(202, png_uint_16, png_get_uint_16, (png_const_bytep buf));
PNG_EXPORT(203, png_int_32, png_get_int_32, (png_const_bytep buf));
#endif
PNG_EXPORT(204, png_uint_32, png_get_uint_31, (png_structp png_ptr,
    png_const_bytep buf));
#ifdef PNG_WRITE_INT_FUNCTIONS_SUPPORTED
PNG_EXPORT(205, void, png_save_uint_32, (png_bytep buf, png_uint_32 i));
#endif
#ifdef PNG_SAVE_INT_32_SUPPORTED
PNG_EXPORT(206, void, png_save_int_32, (png_bytep buf, png_int_32 i));
#endif
#ifdef PNG_WRITE_INT_FUNCTIONS_SUPPORTED
PNG_EXPORT(207, void, png_save_uint_16, (png_bytep buf, unsigned int i));
#endif
#ifdef PNG_USE_READ_MACROS
#  define png_get_uint_32(buf) \
     (((png_uint_32)(*(buf)) << 24) + \
      ((png_uint_32)(*((buf) + 1)) << 16) + \
      ((png_uint_32)(*((buf) + 2)) << 8) + \
      ((png_uint_32)(*((buf) + 3))))
#  define png_get_uint_16(buf) \
     ((png_uint_16) \
      (((unsigned int)(*(buf)) << 8) + \
       ((unsigned int)(*((buf) + 1)))))
#  define png_get_int_32(buf) \
     ((png_int_32)((*(buf) & 0x80) \
      ? -((png_int_32)((png_get_uint_32(buf) ^ 0xffffffffL) + 1)) \
      : (png_int_32)png_get_uint_32(buf)))
#endif
#ifdef PNG_EXPORT_LAST_ORDINAL
  PNG_EXPORT_LAST_ORDINAL(229);
#endif
#ifdef __cplusplus
}
#endif
#endif
#endif
