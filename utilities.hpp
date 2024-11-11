#pragma once

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

// Maximums and minimums for any comparable types
// Base cases
template <typename T>
inline T max(T a, T b) { return a > b ? a : b; }

template <typename T>
inline T min(T a, T b) { return a < b ? a : b; }

// Recursive cases
template <typename T, typename... Args>
inline T max(T a, Args... args) { return max(a, max(args...)); }

template <typename T, typename... Args>
inline T min(T a, Args... args) { return min(a, min(args...)); }

// ---------------------------------------
// Powers
template <typename T>
inline T square(T a) { return a * a; }

// ---------------------------------------
// Clamp
template <typename T>
inline T clamp(T a, T min, T max) { return max(min(a, max), min); }

// ---------------------------------------
// Angles
template <typename T>
inline T rad2deg(T rad) { return rad * 180.0 / M_PI; }

template <typename T>
inline T deg2rad(T deg) { return deg * M_PI / 180.0; }


