#ifndef RVG_RADIAL_GRADIENT_DATA_H
#define RVG_RADIAL_GRADIENT_DATA_H

#include "rvg-ptr.h"
#include "rvg-color-ramp.h"

namespace rvg {

class radial_gradient_data:
    public boost::intrusive_ref_counter<radial_gradient_data> {

    color_ramp::const_ptr m_color_ramp_ptr;
    float m_cx, m_cy, m_fx, m_fy, m_r;

public:
    using ptr = boost::intrusive_ptr<radial_gradient_data>;
    using const_ptr = boost::intrusive_ptr<const radial_gradient_data>;

    radial_gradient_data(color_ramp::const_ptr color_ramp_ptr,
        float cx, float cy, float fx, float fy, float r):
        m_color_ramp_ptr(color_ramp_ptr),
        m_cx(cx),
        m_cy(cy),
        m_fx(fx),
        m_fy(fy),
        m_r(r) { }

    color_ramp::const_ptr get_color_ramp_ptr(void) const {
        return m_color_ramp_ptr;
    }

    const color_ramp &get_color_ramp(void) const {
        return *m_color_ramp_ptr;
    }

    float get_cx(void) const {
        return m_cx;
    }

    float get_cy(void) const {
        return m_cy;
    }

    float get_fx(void) const {
        return m_fx;
    }

    float get_fy(void) const {
        return m_fy;
    }

    float get_r(void) const {
        return m_r;
    }

};

} // namespace rvg

#endif
