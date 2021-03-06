#ifndef RVG_INPUT_PATH_FORWARD_IF_H
#define RVG_INPUT_PATH_FORWARD_IF_H

#include "rvg-i-input-path.h"
#include "rvg-i-point-input-path.h"
#include "rvg-path-f-null.h"

namespace rvg {

template <typename SINK,
    typename = typename std::enable_if<
        rvg::meta::is_an_i_input_path<SINK>::value
    >::type
>
SINK &
make_input_path_f_forward_if(SINK &sink) {
    return sink;
}

template <typename SINK,
    typename = typename std::enable_if<
        !rvg::meta::is_an_i_input_path<SINK>::value
    >::type
>
path_f_null &
make_input_path_f_forward_if(SINK &) {
    static path_f_null pfn{};
    return pfn;
}

} // namespace rvg

#endif
