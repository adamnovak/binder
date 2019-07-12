#include <adaptor/msgpack_tuple.hpp>
#include <algorithm>
#include <arpa/inet.h>
#include <arpa/inet.h>  /* __BYTE_ORDER */
#include <array>
#include <assert.h>
#include <atomic>
#include <cassert>
#include <chrono>
#include <climits>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cstring> // low level mem
#include <deque>
#include <exception>
#include <forward_list>
#include <fstream>
#include <functional>
#include <iomanip>
#include <iostream>
#include <limits.h>
#include <limits>
#include <list>
#include <map>
#include <math.h>
#include <memory>
#include <mmtf.hpp>
#include <mmtf/binary_decoder.hpp>
#include <mmtf/binary_encoder.hpp>
#include <mmtf/custom_zone_type_binding.hpp>
#include <mmtf/decoder.hpp>
#include <mmtf/encoder.hpp>
#include <mmtf/errors.hpp>
#include <mmtf/map_decoder.hpp>
#include <mmtf/msgpack_decoder.hpp>
#include <mmtf/object_encoders.hpp>
#include <mmtf/structure_data.hpp>
#include <msgpack.hpp>
#include <msgpack/adaptor/adaptor_base.hpp>
#include <msgpack/adaptor/adaptor_base_decl.hpp>
#include <msgpack/adaptor/array_ref.hpp>
#include <msgpack/adaptor/array_ref_decl.hpp>
#include <msgpack/adaptor/bool.hpp>
#include <msgpack/adaptor/carray.hpp>
#include <msgpack/adaptor/char_ptr.hpp>
#include <msgpack/adaptor/check_container_size.hpp>
#include <msgpack/adaptor/check_container_size_decl.hpp>
#include <msgpack/adaptor/cpp11/array.hpp>
#include <msgpack/adaptor/cpp11/array_char.hpp>
#include <msgpack/adaptor/cpp11/array_unsigned_char.hpp>
#include <msgpack/adaptor/cpp11/chrono.hpp>
#include <msgpack/adaptor/cpp11/forward_list.hpp>
#include <msgpack/adaptor/cpp11/reference_wrapper.hpp>
#include <msgpack/adaptor/cpp11/shared_ptr.hpp>
#include <msgpack/adaptor/cpp11/tuple.hpp>
#include <msgpack/adaptor/cpp11/unique_ptr.hpp>
#include <msgpack/adaptor/cpp11/unordered_map.hpp>
#include <msgpack/adaptor/cpp11/unordered_set.hpp>
#include <msgpack/adaptor/cpp17/byte.hpp>
#include <msgpack/adaptor/cpp17/carray_byte.hpp>
#include <msgpack/adaptor/cpp17/optional.hpp>
#include <msgpack/adaptor/cpp17/string_view.hpp>
#include <msgpack/adaptor/cpp17/vector_byte.hpp>
#include <msgpack/adaptor/define.hpp>
#include <msgpack/adaptor/define_decl.hpp>
#include <msgpack/adaptor/deque.hpp>
#include <msgpack/adaptor/ext.hpp>
#include <msgpack/adaptor/ext_decl.hpp>
#include <msgpack/adaptor/fixint.hpp>
#include <msgpack/adaptor/fixint_decl.hpp>
#include <msgpack/adaptor/float.hpp>
#include <msgpack/adaptor/int.hpp>
#include <msgpack/adaptor/int_decl.hpp>
#include <msgpack/adaptor/list.hpp>
#include <msgpack/adaptor/map.hpp>
#include <msgpack/adaptor/map_decl.hpp>
#include <msgpack/adaptor/msgpack_tuple.hpp>
#include <msgpack/adaptor/msgpack_tuple_decl.hpp>
#include <msgpack/adaptor/nil.hpp>
#include <msgpack/adaptor/nil_decl.hpp>
#include <msgpack/adaptor/pair.hpp>
#include <msgpack/adaptor/raw.hpp>
#include <msgpack/adaptor/raw_decl.hpp>
#include <msgpack/adaptor/set.hpp>
#include <msgpack/adaptor/size_equal_only.hpp>
#include <msgpack/adaptor/size_equal_only_decl.hpp>
#include <msgpack/adaptor/string.hpp>
#include <msgpack/adaptor/tr1/unordered_map.hpp>
#include <msgpack/adaptor/tr1/unordered_set.hpp>
#include <msgpack/adaptor/v4raw.hpp>
#include <msgpack/adaptor/v4raw_decl.hpp>
#include <msgpack/adaptor/vector.hpp>
#include <msgpack/adaptor/vector_bool.hpp>
#include <msgpack/adaptor/vector_char.hpp>
#include <msgpack/adaptor/vector_unsigned_char.hpp>
#include <msgpack/adaptor/wstring.hpp>
#include <msgpack/cpp_config.hpp>
#include <msgpack/cpp_config_decl.hpp>
#include <msgpack/create_object_visitor.hpp>
#include <msgpack/create_object_visitor_decl.hpp>
#include <msgpack/fbuffer_decl.hpp>
#include <msgpack/iterator.hpp>
#include <msgpack/iterator_decl.hpp>
#include <msgpack/meta.hpp>
#include <msgpack/meta_decl.hpp>
#include <msgpack/null_visitor.hpp>
#include <msgpack/null_visitor_decl.hpp>
#include <msgpack/object.h>
#include <msgpack/object.hpp>
#include <msgpack/object_decl.hpp>
#include <msgpack/object_fwd.hpp>
#include <msgpack/object_fwd_decl.hpp>
#include <msgpack/pack.h>
#include <msgpack/pack.hpp>
#include <msgpack/pack_decl.hpp>
#include <msgpack/pack_define.h>
#include <msgpack/pack_template.h>
#include <msgpack/parse.hpp>
#include <msgpack/parse_decl.hpp>
#include <msgpack/parse_return.hpp>
#include <msgpack/predef.h>
#include <msgpack/predef/architecture.h>
#include <msgpack/predef/architecture/alpha.h>
#include <msgpack/predef/architecture/arm.h>
#include <msgpack/predef/architecture/blackfin.h>
#include <msgpack/predef/architecture/convex.h>
#include <msgpack/predef/architecture/ia64.h>
#include <msgpack/predef/architecture/m68k.h>
#include <msgpack/predef/architecture/mips.h>
#include <msgpack/predef/architecture/parisc.h>
#include <msgpack/predef/architecture/ppc.h>
#include <msgpack/predef/architecture/ptx.h>
#include <msgpack/predef/architecture/pyramid.h>
#include <msgpack/predef/architecture/rs6k.h>
#include <msgpack/predef/architecture/sparc.h>
#include <msgpack/predef/architecture/superh.h>
#include <msgpack/predef/architecture/sys370.h>
#include <msgpack/predef/architecture/sys390.h>
#include <msgpack/predef/architecture/x86.h>
#include <msgpack/predef/architecture/x86/32.h>
#include <msgpack/predef/architecture/x86/64.h>
#include <msgpack/predef/architecture/z.h>
#include <msgpack/predef/compiler.h>
#include <msgpack/predef/compiler/borland.h>
#include <msgpack/predef/compiler/clang.h>
#include <msgpack/predef/compiler/comeau.h>
#include <msgpack/predef/compiler/compaq.h>
#include <msgpack/predef/compiler/diab.h>
#include <msgpack/predef/compiler/digitalmars.h>
#include <msgpack/predef/compiler/dignus.h>
#include <msgpack/predef/compiler/edg.h>
#include <msgpack/predef/compiler/ekopath.h>
#include <msgpack/predef/compiler/gcc.h>
#include <msgpack/predef/compiler/gcc_xml.h>
#include <msgpack/predef/compiler/greenhills.h>
#include <msgpack/predef/compiler/hp_acc.h>
#include <msgpack/predef/compiler/iar.h>
#include <msgpack/predef/compiler/ibm.h>
#include <msgpack/predef/compiler/intel.h>
#include <msgpack/predef/compiler/kai.h>
#include <msgpack/predef/compiler/llvm.h>
#include <msgpack/predef/compiler/metaware.h>
#include <msgpack/predef/compiler/metrowerks.h>
#include <msgpack/predef/compiler/microtec.h>
#include <msgpack/predef/compiler/mpw.h>
#include <msgpack/predef/compiler/nvcc.h>
#include <msgpack/predef/compiler/palm.h>
#include <msgpack/predef/compiler/pgi.h>
#include <msgpack/predef/compiler/sgi_mipspro.h>
#include <msgpack/predef/compiler/sunpro.h>
#include <msgpack/predef/compiler/tendra.h>
#include <msgpack/predef/compiler/visualc.h>
#include <msgpack/predef/compiler/watcom.h>
#include <msgpack/predef/detail/_cassert.h>
#include <msgpack/predef/detail/_exception.h>
#include <msgpack/predef/detail/test.h>
#include <msgpack/predef/hardware.h>
#include <msgpack/predef/hardware/simd.h>
#include <msgpack/predef/hardware/simd/arm.h>
#include <msgpack/predef/hardware/simd/arm/versions.h>
#include <msgpack/predef/hardware/simd/ppc.h>
#include <msgpack/predef/hardware/simd/ppc/versions.h>
#include <msgpack/predef/hardware/simd/x86.h>
#include <msgpack/predef/hardware/simd/x86/versions.h>
#include <msgpack/predef/hardware/simd/x86_amd.h>
#include <msgpack/predef/hardware/simd/x86_amd/versions.h>
#include <msgpack/predef/language.h>
#include <msgpack/predef/language/cuda.h>
#include <msgpack/predef/language/objc.h>
#include <msgpack/predef/language/stdc.h>
#include <msgpack/predef/language/stdcpp.h>
#include <msgpack/predef/library.h>
#include <msgpack/predef/library/c.h>
#include <msgpack/predef/library/c/_prefix.h>
#include <msgpack/predef/library/c/cloudabi.h>
#include <msgpack/predef/library/c/gnu.h>
#include <msgpack/predef/library/c/uc.h>
#include <msgpack/predef/library/c/vms.h>
#include <msgpack/predef/library/c/zos.h>
#include <msgpack/predef/library/std.h>
#include <msgpack/predef/library/std/_prefix.h>
#include <msgpack/predef/library/std/cxx.h>
#include <msgpack/predef/library/std/dinkumware.h>
#include <msgpack/predef/library/std/libcomo.h>
#include <msgpack/predef/library/std/modena.h>
#include <msgpack/predef/library/std/msl.h>
#include <msgpack/predef/library/std/roguewave.h>
#include <msgpack/predef/library/std/sgi.h>
#include <msgpack/predef/library/std/stdcpp3.h>
#include <msgpack/predef/library/std/stlport.h>
#include <msgpack/predef/library/std/vacpp.h>
#include <msgpack/predef/make.h>
#include <msgpack/predef/os.h>
#include <msgpack/predef/os/aix.h>
#include <msgpack/predef/os/amigaos.h>
#include <msgpack/predef/os/android.h>
#include <msgpack/predef/os/beos.h>
#include <msgpack/predef/os/bsd.h>
#include <msgpack/predef/os/bsd/bsdi.h>
#include <msgpack/predef/os/bsd/dragonfly.h>
#include <msgpack/predef/os/bsd/free.h>
#include <msgpack/predef/os/bsd/net.h>
#include <msgpack/predef/os/bsd/open.h>
#include <msgpack/predef/os/cygwin.h>
#include <msgpack/predef/os/haiku.h>
#include <msgpack/predef/os/hpux.h>
#include <msgpack/predef/os/ios.h>
#include <msgpack/predef/os/ios.h> // MSGPACK_OS_IOS
#include <msgpack/predef/os/irix.h>
#include <msgpack/predef/os/linux.h>
#include <msgpack/predef/os/macos.h>
#include <msgpack/predef/os/os400.h>
#include <msgpack/predef/os/qnxnto.h>
#include <msgpack/predef/os/solaris.h>
#include <msgpack/predef/os/unix.h>
#include <msgpack/predef/os/vms.h>
#include <msgpack/predef/os/windows.h>
#include <msgpack/predef/other.h>
#include <msgpack/predef/other/endian.h>
#include <msgpack/predef/platform.h>
#include <msgpack/predef/platform/cloudabi.h>
#include <msgpack/predef/platform/ios.h>
#include <msgpack/predef/platform/mingw.h>
#include <msgpack/predef/platform/mingw32.h>
#include <msgpack/predef/platform/mingw64.h>
#include <msgpack/predef/platform/windows_desktop.h>
#include <msgpack/predef/platform/windows_phone.h>
#include <msgpack/predef/platform/windows_runtime.h> // deprecated
#include <msgpack/predef/platform/windows_server.h>
#include <msgpack/predef/platform/windows_store.h>
#include <msgpack/predef/platform/windows_system.h>
#include <msgpack/predef/platform/windows_uwp.h>
#include <msgpack/predef/version.h>
#include <msgpack/predef/version_number.h>
#include <msgpack/predef/version_number.h> // MSGPACK_VERSION_NUMBER_NOT_AVAILABLE
#include <msgpack/preprocessor.hpp>
#include <msgpack/preprocessor/config/config.hpp>
#include <msgpack/preprocessor/control/iif.hpp>
#include <msgpack/preprocessor/facilities/empty.hpp>
#include <msgpack/preprocessor/facilities/identity.hpp>
#include <msgpack/preprocessor/punctuation/detail/is_begin_parens.hpp>
#include <msgpack/preprocessor/punctuation/is_begin_parens.hpp>
#include <msgpack/preprocessor/tuple/enum.hpp>
#include <msgpack/sbuffer.h>
#include <msgpack/sbuffer.hpp>
#include <msgpack/sbuffer_decl.hpp>
#include <msgpack/sysdep.h>
#include <msgpack/timestamp.h>
#include <msgpack/type.hpp>
#include <msgpack/unpack.h>
#include <msgpack/unpack.hpp>
#include <msgpack/unpack_decl.hpp>
#include <msgpack/unpack_define.h>
#include <msgpack/unpack_exception.hpp>
#include <msgpack/util.h>
#include <msgpack/v1/adaptor/adaptor_base.hpp>
#include <msgpack/v1/adaptor/adaptor_base_decl.hpp>
#include <msgpack/v1/adaptor/array_ref.hpp>
#include <msgpack/v1/adaptor/array_ref_decl.hpp>
#include <msgpack/v1/adaptor/bool.hpp>
#include <msgpack/v1/adaptor/carray.hpp>
#include <msgpack/v1/adaptor/char_ptr.hpp>
#include <msgpack/v1/adaptor/check_container_size.hpp>
#include <msgpack/v1/adaptor/check_container_size_decl.hpp>
#include <msgpack/v1/adaptor/cpp11/array.hpp>
#include <msgpack/v1/adaptor/cpp11/array_char.hpp>
#include <msgpack/v1/adaptor/cpp11/array_unsigned_char.hpp>
#include <msgpack/v1/adaptor/cpp11/chrono.hpp>
#include <msgpack/v1/adaptor/cpp11/forward_list.hpp>
#include <msgpack/v1/adaptor/cpp11/reference_wrapper.hpp>
#include <msgpack/v1/adaptor/cpp11/shared_ptr.hpp>
#include <msgpack/v1/adaptor/cpp11/tuple.hpp>
#include <msgpack/v1/adaptor/cpp11/unique_ptr.hpp>
#include <msgpack/v1/adaptor/cpp11/unordered_map.hpp>
#include <msgpack/v1/adaptor/cpp11/unordered_set.hpp>
#include <msgpack/v1/adaptor/cpp17/byte.hpp>
#include <msgpack/v1/adaptor/cpp17/carray_byte.hpp>
#include <msgpack/v1/adaptor/cpp17/optional.hpp>
#include <msgpack/v1/adaptor/cpp17/string_view.hpp>
#include <msgpack/v1/adaptor/cpp17/vector_byte.hpp>
#include <msgpack/v1/adaptor/define.hpp>
#include <msgpack/v1/adaptor/define_decl.hpp>
#include <msgpack/v1/adaptor/deque.hpp>
#include <msgpack/v1/adaptor/detail/cpp03_define_array.hpp>
#include <msgpack/v1/adaptor/detail/cpp03_define_array_decl.hpp>
#include <msgpack/v1/adaptor/detail/cpp03_define_map.hpp>
#include <msgpack/v1/adaptor/detail/cpp03_define_map_decl.hpp>
#include <msgpack/v1/adaptor/detail/cpp03_msgpack_tuple.hpp>
#include <msgpack/v1/adaptor/detail/cpp03_msgpack_tuple_decl.hpp>
#include <msgpack/v1/adaptor/detail/cpp11_convert_helper.hpp>
#include <msgpack/v1/adaptor/detail/cpp11_define_array.hpp>
#include <msgpack/v1/adaptor/detail/cpp11_define_array_decl.hpp>
#include <msgpack/v1/adaptor/detail/cpp11_define_map.hpp>
#include <msgpack/v1/adaptor/detail/cpp11_define_map_decl.hpp>
#include <msgpack/v1/adaptor/detail/cpp11_msgpack_tuple.hpp>
#include <msgpack/v1/adaptor/detail/cpp11_msgpack_tuple_decl.hpp>
#include <msgpack/v1/adaptor/ext.hpp>
#include <msgpack/v1/adaptor/ext_decl.hpp>
#include <msgpack/v1/adaptor/fixint.hpp>
#include <msgpack/v1/adaptor/fixint_decl.hpp>
#include <msgpack/v1/adaptor/float.hpp>
#include <msgpack/v1/adaptor/int.hpp>
#include <msgpack/v1/adaptor/int_decl.hpp>
#include <msgpack/v1/adaptor/list.hpp>
#include <msgpack/v1/adaptor/map.hpp>
#include <msgpack/v1/adaptor/map_decl.hpp>
#include <msgpack/v1/adaptor/msgpack_tuple.hpp>
#include <msgpack/v1/adaptor/msgpack_tuple_decl.hpp>
#include <msgpack/v1/adaptor/nil.hpp>
#include <msgpack/v1/adaptor/nil_decl.hpp>
#include <msgpack/v1/adaptor/pair.hpp>
#include <msgpack/v1/adaptor/raw.hpp>
#include <msgpack/v1/adaptor/raw_decl.hpp>
#include <msgpack/v1/adaptor/set.hpp>
#include <msgpack/v1/adaptor/size_equal_only.hpp>
#include <msgpack/v1/adaptor/size_equal_only_decl.hpp>
#include <msgpack/v1/adaptor/string.hpp>
#include <msgpack/v1/adaptor/v4raw.hpp>
#include <msgpack/v1/adaptor/v4raw_decl.hpp>
#include <msgpack/v1/adaptor/vector.hpp>
#include <msgpack/v1/adaptor/vector_bool.hpp>
#include <msgpack/v1/adaptor/vector_char.hpp>
#include <msgpack/v1/adaptor/vector_unsigned_char.hpp>
#include <msgpack/v1/adaptor/wstring.hpp>
#include <msgpack/v1/cpp_config.hpp>
#include <msgpack/v1/cpp_config_decl.hpp>
#include <msgpack/v1/detail/cpp03_zone.hpp>
#include <msgpack/v1/detail/cpp03_zone_decl.hpp>
#include <msgpack/v1/detail/cpp11_zone.hpp>
#include <msgpack/v1/detail/cpp11_zone_decl.hpp>
#include <msgpack/v1/fbuffer.hpp>
#include <msgpack/v1/fbuffer_decl.hpp>
#include <msgpack/v1/iterator.hpp>
#include <msgpack/v1/iterator_decl.hpp>
#include <msgpack/v1/meta.hpp>
#include <msgpack/v1/meta_decl.hpp>
#include <msgpack/v1/object.hpp>
#include <msgpack/v1/object_decl.hpp>
#include <msgpack/v1/object_fwd.hpp>
#include <msgpack/v1/object_fwd_decl.hpp>
#include <msgpack/v1/pack.hpp>
#include <msgpack/v1/pack_decl.hpp>
#include <msgpack/v1/parse_return.hpp>
#include <msgpack/v1/sbuffer.hpp>
#include <msgpack/v1/sbuffer_decl.hpp>
#include <msgpack/v1/unpack.hpp>
#include <msgpack/v1/unpack_decl.hpp>
#include <msgpack/v1/unpack_exception.hpp>
#include <msgpack/v1/vrefbuffer.hpp>
#include <msgpack/v1/vrefbuffer_decl.hpp>
#include <msgpack/v1/zbuffer.hpp>
#include <msgpack/v1/zbuffer_decl.hpp>
#include <msgpack/v1/zone.hpp>
#include <msgpack/v1/zone_decl.hpp>
#include <msgpack/v2/adaptor/adaptor_base.hpp>
#include <msgpack/v2/adaptor/adaptor_base_decl.hpp>
#include <msgpack/v2/adaptor/array_ref_decl.hpp>
#include <msgpack/v2/adaptor/check_container_size_decl.hpp>
#include <msgpack/v2/adaptor/define_decl.hpp>
#include <msgpack/v2/adaptor/detail/cpp03_define_array_decl.hpp>
#include <msgpack/v2/adaptor/detail/cpp03_define_map_decl.hpp>
#include <msgpack/v2/adaptor/detail/cpp03_msgpack_tuple_decl.hpp>
#include <msgpack/v2/adaptor/detail/cpp11_define_array_decl.hpp>
#include <msgpack/v2/adaptor/detail/cpp11_define_map_decl.hpp>
#include <msgpack/v2/adaptor/detail/cpp11_msgpack_tuple_decl.hpp>
#include <msgpack/v2/adaptor/ext_decl.hpp>
#include <msgpack/v2/adaptor/fixint_decl.hpp>
#include <msgpack/v2/adaptor/int_decl.hpp>
#include <msgpack/v2/adaptor/map_decl.hpp>
#include <msgpack/v2/adaptor/msgpack_tuple_decl.hpp>
#include <msgpack/v2/adaptor/nil_decl.hpp>
#include <msgpack/v2/adaptor/raw_decl.hpp>
#include <msgpack/v2/adaptor/size_equal_only_decl.hpp>
#include <msgpack/v2/adaptor/v4raw_decl.hpp>
#include <msgpack/v2/cpp_config_decl.hpp>
#include <msgpack/v2/create_object_visitor.hpp>
#include <msgpack/v2/create_object_visitor_decl.hpp>
#include <msgpack/v2/detail/cpp03_zone_decl.hpp>
#include <msgpack/v2/detail/cpp11_zone_decl.hpp>
#include <msgpack/v2/fbuffer_decl.hpp>
#include <msgpack/v2/iterator_decl.hpp>
#include <msgpack/v2/meta_decl.hpp>
#include <msgpack/v2/null_visitor.hpp>
#include <msgpack/v2/null_visitor_decl.hpp>
#include <msgpack/v2/object.hpp>
#include <msgpack/v2/object_decl.hpp>
#include <msgpack/v2/object_fwd.hpp>
#include <msgpack/v2/object_fwd_decl.hpp>
#include <msgpack/v2/pack_decl.hpp>
#include <msgpack/v2/parse.hpp>
#include <msgpack/v2/parse_decl.hpp>
#include <msgpack/v2/parse_return.hpp>
#include <msgpack/v2/sbuffer_decl.hpp>
#include <msgpack/v2/unpack.hpp>
#include <msgpack/v2/unpack_decl.hpp>
#include <msgpack/v2/vrefbuffer_decl.hpp>
#include <msgpack/v2/x3_parse.hpp>
#include <msgpack/v2/x3_parse_decl.hpp>
#include <msgpack/v2/x3_unpack.hpp>
#include <msgpack/v2/x3_unpack_decl.hpp>
#include <msgpack/v2/zbuffer_decl.hpp>
#include <msgpack/v2/zone_decl.hpp>
#include <msgpack/v3/adaptor/adaptor_base.hpp>
#include <msgpack/v3/adaptor/adaptor_base_decl.hpp>
#include <msgpack/v3/adaptor/array_ref_decl.hpp>
#include <msgpack/v3/adaptor/check_container_size_decl.hpp>
#include <msgpack/v3/adaptor/define_decl.hpp>
#include <msgpack/v3/adaptor/detail/cpp03_define_array_decl.hpp>
#include <msgpack/v3/adaptor/detail/cpp03_define_map_decl.hpp>
#include <msgpack/v3/adaptor/detail/cpp03_msgpack_tuple_decl.hpp>
#include <msgpack/v3/adaptor/detail/cpp11_define_array_decl.hpp>
#include <msgpack/v3/adaptor/detail/cpp11_define_map_decl.hpp>
#include <msgpack/v3/adaptor/detail/cpp11_msgpack_tuple_decl.hpp>
#include <msgpack/v3/adaptor/ext_decl.hpp>
#include <msgpack/v3/adaptor/fixint_decl.hpp>
#include <msgpack/v3/adaptor/int_decl.hpp>
#include <msgpack/v3/adaptor/map_decl.hpp>
#include <msgpack/v3/adaptor/msgpack_tuple_decl.hpp>
#include <msgpack/v3/adaptor/nil_decl.hpp>
#include <msgpack/v3/adaptor/raw_decl.hpp>
#include <msgpack/v3/adaptor/size_equal_only_decl.hpp>
#include <msgpack/v3/adaptor/v4raw_decl.hpp>
#include <msgpack/v3/cpp_config_decl.hpp>
#include <msgpack/v3/create_object_visitor_decl.hpp>
#include <msgpack/v3/detail/cpp03_zone_decl.hpp>
#include <msgpack/v3/detail/cpp11_zone_decl.hpp>
#include <msgpack/v3/fbuffer_decl.hpp>
#include <msgpack/v3/iterator_decl.hpp>
#include <msgpack/v3/meta_decl.hpp>
#include <msgpack/v3/null_visitor_decl.hpp>
#include <msgpack/v3/object_decl.hpp>
#include <msgpack/v3/object_fwd.hpp>
#include <msgpack/v3/object_fwd_decl.hpp>
#include <msgpack/v3/pack_decl.hpp>
#include <msgpack/v3/parse.hpp>
#include <msgpack/v3/parse_decl.hpp>
#include <msgpack/v3/parse_return.hpp>
#include <msgpack/v3/sbuffer_decl.hpp>
#include <msgpack/v3/unpack.hpp>
#include <msgpack/v3/unpack_decl.hpp>
#include <msgpack/v3/vrefbuffer_decl.hpp>
#include <msgpack/v3/x3_parse_decl.hpp>
#include <msgpack/v3/x3_unpack.hpp>
#include <msgpack/v3/x3_unpack_decl.hpp>
#include <msgpack/v3/zbuffer_decl.hpp>
#include <msgpack/v3/zone_decl.hpp>
#include <msgpack/version.h>
#include <msgpack/version.hpp>
#include <msgpack/version_master.h>
#include <msgpack/versioning.hpp>
#include <msgpack/vrefbuffer.h>
#include <msgpack/vrefbuffer.hpp>
#include <msgpack/vrefbuffer_decl.hpp>
#include <msgpack/x3_parse.hpp>
#include <msgpack/x3_parse_decl.hpp>
#include <msgpack/x3_unpack.hpp>
#include <msgpack/x3_unpack_decl.hpp>
#include <msgpack/zbuffer_decl.hpp>
#include <msgpack/zone.h>
#include <msgpack/zone.hpp>
#include <msgpack/zone_decl.hpp>
#include <optional>
#include <ostream>
#include <pybind11/stl_bind.h>
#include <set>
#include <sstream>
#include <stddef.h>
#include <stdexcept>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <string_view>
#include <sys/uio.h>
#include <tr1/unordered_map>
#include <tr1/unordered_set>
#include <tuple>
#include <type_traits>
#include <typeinfo>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
#include <zlib.h>
#include _msgpack_atomic_counter_header