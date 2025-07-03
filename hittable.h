#ifndef HITTABLE_H
#define HITTABLE_H

#include "rtweekend.h"

class material;

class hit_record {
public:
	point3 p;
	vec3 normal;
	shared_ptr<material> mat;
	double t;
	bool front_face;

	void set_face_normal(const ray& r, const vec3& out_normal) {
		// Set the hit record normal vector
		// NOTE: the parameter 'outward_normal' is assumed to have unit length

		front_face = dot(r.direction(), out_normal) < 0;
		normal = front_face ? out_normal : -out_normal;
	}
};

class hittable {
public:
	virtual ~hittable() = default;

	virtual bool hit(const ray& r, interval ray_t, hit_record& rec) const = 0;
};

#endif
