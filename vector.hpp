#pragma once

#include <cmath>

template<class T>
struct Vector2 {
	T x{}, y{};

	constexpr Vector2(T const x, T const y) noexcept
		: x(x), y(y) {}

	Vector2 &operator=(Vector2 const &other) noexcept {
		x = other.x;
		y = other.y;
		return *this;
	}

	Vector2 &operator+=(Vector2 const &other) noexcept {
		x += other.x;
		y += other.y;
		return *this;
	}

	Vector2 &operator-=(Vector2 const &other) noexcept {
		x -= other.x;
		y -= other.y;
		return *this;
	}

	Vector2 &operator*=(Vector2 const &other) noexcept {
		x *= other.x;
		y *= other.y;
		return *this;
	}

	Vector2 &operator/=(Vector2 const &other) {
		x /= other.x;
		y /= other.y;
		return *this;
	}

	Vector2 &operator%=(Vector2 const &other) noexcept {
		x %= other.x;
		y %= other.y;
		return *this;
	}

	Vector2 &operator*=(T const scalar) noexcept {
		x *= scalar;
		y *= scalar;
		return *this;
	}

	Vector2 &operator/=(T const scalar) {
		x /= scalar;
		y /= scalar;
		return *this;
	}

	constexpr auto operator<=>(Vector2 const&) const = default;

	constexpr Vector2 operator-() {
		return { -x, -y };
	}

	constexpr Vector2 operator+() {
		return *this;
	}

	constexpr T length() const noexcept {
		return std::sqrt(x * x + y * y);
	}

	constexpr T square_length() const noexcept {
		return x * x + y * y;
	}

	constexpr Vector2 normalized() const {
		return *this / length();
	}

	Vector2 &normalize() {
		return *this /= length();
	}

	constexpr T dot(Vector2 const &other) const noexcept {
		return x * other.x + y * other.y;
	}

	constexpr T cross(Vector2 const &other) const noexcept {
		return x * other.y - y * other.x;
	}

	constexpr T angle() const noexcept {
		return std::atan2(y, x);
	}
};

template<class T>
Vector2<T> operator+(Vector2<T> const &left, Vector2<T> const &right) noexcept {
	return { left.x + right.x, left.y + right.y };
}

template<class T>
Vector2<T> operator-(Vector2<T> const &left, Vector2<T> const &right) noexcept {
	return { left.x - right.x, left.y - right.y };
}

template<class T>
Vector2<T> operator*(Vector2<T> const &left, Vector2<T> const &right) noexcept {
	return { left.x * right.x, left.y * right.y };
}

template<class T>
Vector2<T> operator/(Vector2<T> const &left, Vector2<T> const &right) {
	return { left.x / right.x, left.y / right.y };
}

template<class T>
Vector2<T> operator%(Vector2<T> const &left, Vector2<T> const &right) noexcept {
	return { left.x % right.x, left.y % right.y };
}

template<class T>
Vector2<T> operator*(Vector2<T> const &vec, T const scalar) noexcept {
	return { vec.x * scalar, vec.y * scalar };
}

template<class T>
Vector2<T> operator/(Vector2<T> const &vec, T const scalar) {
	return { vec.x / scalar, vec.y / scalar };
}

template<class T>
struct Vector3 {
	T x{}, y{}, z{};

	constexpr Vector3(T const x, T const y, T const z) noexcept
		: x(x), y(y), z(z) {}

	Vector3 &operator=(Vector3 const &other) noexcept {
		x = other.x;
		y = other.y;
		z = other.z;
		return *this;
	}

	Vector3 &operator+=(Vector3 const &other) noexcept {
		x += other.x;
		y += other.y;
		z += other.z;
		return *this;
	}

	Vector3 &operator-=(Vector3 const &other) noexcept {
		x -= other.x;
		y -= other.y;
		z -= other.z;
		return *this;
	}

	Vector3 &operator*=(Vector3 const &other) noexcept {
		x *= other.x;
		y *= other.y;
		z *= other.z;
		return *this;
	}

	Vector3 &operator/=(Vector3 const &other) {
		x /= other.x;
		y /= other.y;
		z /= other.z;
		return *this;
	}

	Vector3 &operator%=(Vector3 const &other) noexcept {
		x %= other.x;
		y %= other.y;
		z %= other.z;
		return *this;
	}

	Vector3 &operator*=(T const scalar) noexcept {
		x *= scalar;
		y *= scalar;
		z *= scalar;
		return *this;
	}

	Vector3 &operator/=(T const scalar) {
		x /= scalar;
		y /= scalar;
		z /= scalar;
		return *this;
	}

	constexpr auto operator<=>(Vector3 const&) const = default;

	constexpr Vector3 operator-() {
		return { -x, -y, -z };
	}

	constexpr Vector3 operator+() {
		return *this;
	}

	constexpr T length() const noexcept {
		return std::sqrt(x * x + y * y + z * z);
	}

	constexpr T square_length() const noexcept {
		return x * x + y * y + z * z;
	}

	constexpr Vector3 normalized() const {
		return *this / length();
	}

	Vector3 &normalize() {
		return *this /= length();
	}

	constexpr T dot(Vector3 const &other) const noexcept {
		return x * other.x + y * other.y + z * other.z;
	}

	constexpr Vector3 cross(Vector3 const &other) const noexcept {
		return { y * other.z - z * other.y, z * other.x - x * other.z,
			x * other.y - y * other.x };
	}
};

template<class T>
Vector3<T> operator+(Vector3<T> const &left, Vector3<T> const &right) noexcept {
	return { left.x + right.x, left.y + right.y, left.z + right.z };
}

template<class T>
Vector3<T> operator-(Vector3<T> const &left, Vector3<T> const &right) noexcept {
	return { left.x - right.x, left.y - right.y, left.z - right.z };
}

template<class T>
Vector3<T> operator*(Vector3<T> const &left, Vector3<T> const &right) noexcept {
	return { left.x * right.x, left.y * right.y, left.z * right.z };
}

template<class T>
Vector3<T> operator/(Vector3<T> const &left, Vector3<T> const &right) {
	return { left.x / right.x, left.y / right.y, left.z / right.z };
}

template<class T>
Vector3<T> operator%(Vector3<T> const &left, Vector3<T> const &right) noexcept {
	return { left.x % right.x, left.y % right.y, left.z % right.z };
}

template<class T>
Vector3<T> operator*(Vector3<T> const &vec, T const scalar) noexcept {
	return { vec.x * scalar, vec.y * scalar, vec.z * scalar };
}

template<class T>
Vector3<T> operator/(Vector3<T> const &vec, T const scalar) {
	return { vec.x / scalar, vec.y / scalar, vec.z / scalar };
}

template<class T>
struct PitchYaw {
	T pitch{}; // Counterclockwise rotation around X axis
	T yaw{}; // Counterclockwise rotation around Y axis

	// 0, 0 => Right
	// 0, pi/2 => Forward
	// pi/2, 0 => Up

	constexpr PitchYaw(T const pitch, T const yaw) noexcept
		: pitch(pitch), yaw(yaw) {}
};

template<class T>
constexpr Vector2<T> Vector2_from_angle(T const ang) noexcept {
	return { std::cos(ang), std::sin(ang) };
}

template<class T>
constexpr PitchYaw<T> PitchYaw_from_Vector3(Vector3<T> const &vec) noexcept {
	return { std::asin(vec.y), std::atan2(vec.z, vec.x) };
}

template<class T>
constexpr Vector3<T> Vector3_from_PitchYaw(PitchYaw<T> const &pitch_yaw) {
	auto[pitch, yaw] = pitch_yaw;
	return { std::cos(yaw) * std::cos(pitch), std::sin(pitch),
		std::sin(yaw) * std::cos(pitch) };
}
