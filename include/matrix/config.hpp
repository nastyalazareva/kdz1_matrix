#pragma once
#include <cstddef>
#include <cstdint>
using Elem = std::uint32_t; // тип элемента матрицы
// Рабочий размер стековой матрицы. Значение времени компиляции.
inline constexpr std::size_t kStackN = 500;