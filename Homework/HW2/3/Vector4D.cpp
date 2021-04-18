#include "Vector4D.hpp"
#include <iostream>

Vector4D::Vector4D() {
	vec.push_back(0);
	vec.push_back(0);
	vec.push_back(0);
	vec.push_back(0);
}

Vector4D::Vector4D(double el1, double el2, double el3, double el4) {
	vec.push_back(el1);
	vec.push_back(el2);
	vec.push_back(el3);
	vec.push_back(el4);

}
double& Vector4D::operator[](int index) {
	return vec[index];
}

Vector4D Vector4D::operator+(const Vector4D& rhs) const {
	Vector4D temp;

	for (size_t i = 0; i < temp.vec.size();i++) {
		temp[i] = this->vec[i] + rhs.vec[i];
	}

	return temp;
}
Vector4D& Vector4D::operator+=(const Vector4D& rhs) {
	for (size_t i = 0; i < this->vec.size();i++) {
		this->vec[i] += rhs.vec[i];
	}

	return *this;
}

Vector4D Vector4D::operator-(const Vector4D& rhs) const {
	Vector4D temp;

	for (size_t i = 0; i < temp.vec.size();i++) {
		temp[i] = this->vec[i] - rhs.vec[i];
	}

	return temp;
}
Vector4D& Vector4D::operator-=(const Vector4D& rhs) {
	for (size_t i = 0; i < this->vec.size();i++) {
		this->vec[i] -= rhs.vec[i];
	}

	return *this;
}


Vector4D Vector4D::operator*(const Vector4D& rhs) const {
	Vector4D temp;

	for (size_t i = 0; i < temp.vec.size();i++) {
		temp[i] = this->vec[i] * rhs.vec[i];
	}

	return temp;
}
Vector4D& Vector4D::operator*=(const Vector4D& rhs) {
	for (size_t i = 0; i < this->vec.size();i++) {
		this->vec[i] *= rhs.vec[i];
	}

	return *this;
}
Vector4D Vector4D::operator*(double value) const {
	Vector4D temp;

	for (size_t i = 0; i < temp.vec.size();i++) {
		temp[i] = this->vec[i] * value;
	}

	return temp;
}
Vector4D& Vector4D::operator*=(double value) {
	for (size_t i = 0; i < this->vec.size();i++) {
		this->vec[i] *= value;
	}

	return *this;
}

Vector4D Vector4D::operator/(const Vector4D& rhs) const {
	Vector4D temp;

	for (size_t i = 0; i < temp.vec.size();i++) {
		temp[i] = this->vec[i] / rhs.vec[i];
	}

	return temp;
}
Vector4D& Vector4D::operator/=(const Vector4D& rhs) {
	for (size_t i = 0; i < this->vec.size();i++) {
		this->vec[i] /= rhs.vec[i];
	}

	return *this;
}

bool Vector4D::operator==(const Vector4D& rhs) const {
	for (size_t i = 0; i < this->vec.size();i++) {
		if (this->vec[i] != rhs.vec[i]) {
			return false;
		}
	}
	return true;
}
bool Vector4D::operator!=(const Vector4D& rhs) const {
	for (size_t i = 0; i < this->vec.size();i++) {
		if (this->vec[i] != rhs.vec[i]) {
			return true;
		}

	}
	return false;
}

bool Vector4D::operator>(const Vector4D& rhs) const {
	for (size_t i = 0; i < this->vec.size();i++) {
		if (this->vec[i] > rhs.vec[i]) {
			return true;
		}
		else if (this->vec[i] < rhs.vec[i]) {
			return false;
		}
		else {
			continue;
		}
	}
	return false;
}
bool Vector4D::operator>=(const Vector4D& rhs) const {
	for (size_t i = 0; i < this->vec.size();i++) {
		if (this->vec[i] < rhs.vec[i]) {
			return false;
		}
		else if(this->vec[i] > rhs.vec[i]) {
			return true;
		}
		else {
			continue;
		}
	}
	return true;
}

bool Vector4D::operator<(const Vector4D& rhs) const {
	for (size_t i = 0; i < this->vec.size();i++) {
		if (this->vec[i] < rhs.vec[i]) {
			return true;
		}
		else if (this->vec[i] > rhs.vec[i]) {
			return false;
		}
		else {
			continue;
		}
	}
	return false;
}
bool Vector4D::operator<=(const Vector4D& rhs) const {
	for (size_t i = 0; i < this->vec.size();i++) {
		if (this->vec[i] > rhs.vec[i]) {
			return false;
		}
		else if (this->vec[i] < rhs.vec[i]) {
			return true;
		}
		else {
			continue;
		}
	}
	return true;
}

bool Vector4D::operator!() const {
	for (size_t i = 0; i < this->vec.size();i++) {
		if (this->vec[i] != 0) {
			return false;
		}
	}
	return true;
}

Vector4D Vector4D::operator-() const {
	Vector4D temp;

	for (size_t i = 0; i < temp.vec.size();i++) {
		temp[i] = - (this->vec[i]);
	}

	return temp;
}


void Vector4D::printVec() {
	for (const auto x : vec) {
		std::cout << x << ' ';
	}
	std::cout << std::endl;
}