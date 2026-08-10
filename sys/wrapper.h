#ifndef CEF_RUST_SYS_WRAPPER_H
#define CEF_RUST_SYS_WRAPPER_H

#ifdef __APPLE__
#include "include/wrapper/cef_library_loader.h"
#include "include/cef_sandbox_mac.h"
#endif

#include "include/cef_version.h"

// CEF 3.x (including branch 2704) defines API hashes in cef_version.h and
// does not provide the newer cef_api_hash.h header.
#if CEF_VERSION_MAJOR != 3
#include "include/cef_api_hash.h"
#endif

#include "include/capi/cef_base_capi.h"

// CEF 3.x uses cef_base_t for reference-counted objects and represents the
// string collection handles as void pointers. Keep the names expected by the
// safe bindings available when generating against that API.
#if CEF_VERSION_MAJOR == 3
typedef struct _cef_base_t _cef_base_ref_counted_t;
typedef _cef_base_ref_counted_t cef_base_ref_counted_t;
typedef void _cef_string_list_t;
typedef void _cef_string_map_t;
typedef void _cef_string_multimap_t;
#endif

#include "include/capi/cef_app_capi.h"
#include "include/capi/cef_client_capi.h"
#include "include/capi/cef_urlrequest_capi.h"

#include "include/capi/views/cef_layout_capi.h"
#include "include/capi/views/cef_box_layout_capi.h"
#include "include/capi/views/cef_fill_layout_capi.h"

#include "include/capi/views/cef_button_capi.h"
#include "include/capi/views/cef_label_button_capi.h"
#include "include/capi/views/cef_menu_button_capi.h"

#include "include/capi/views/cef_textfield_capi.h"

#include "include/capi/views/cef_browser_view_capi.h"
#include "include/capi/views/cef_scroll_view_capi.h"

#include "include/capi/views/cef_window_capi.h"

#endif
