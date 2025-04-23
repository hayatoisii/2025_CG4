struct Vector3 final {  
   float x, y, z;  

   // ���ς��v�Z���郁���o�[�֐�  
   float dot(const Vector3& other) const { return x * other.x + y * other.y + z * other.z; }  

   // �X�J���[�{���s�������o�[�֐�  
   Vector3 scale(float scalar) const { return {x * scalar, y * scalar, z * scalar}; }  

   // ���Z�q�I�[�o�[���[�h  
   Vector3 operator+(const Vector3& other) const { return {x + other.x, y + other.y, z + other.z}; }  

   Vector3 operator-(const Vector3& other) const { return {x - other.x, y - other.y, z - other.z}; }  

   Vector3 operator/(float scalar) const { return {x / scalar, y / scalar, z / scalar}; }  
   Vector3 operator-(float scalar) const { return {x - scalar, y - scalar, z - scalar}; }  
   Vector3 operator+(float scalar) const { return {x + scalar, y + scalar, z + scalar}; }  

   // �x�N�g���̒����̓����v�Z���郁���o�[�֐�  
   float lengthSquared() const { return x * x + y * y + z * z; }  

   // += ���Z�q�̃I�[�o�[���[�h  
   Vector3& operator+=(const Vector3& other) {  
       this->x += other.x;  
       this->y += other.y;  
       this->z += other.z;  
       return *this;  
   }  

   // �C��: += ���Z�q�̃I�[�o�[���[�h (�X�J���[�l)  
   Vector3& operator+=(float scalar) {  
       this->x += scalar;  
       this->y += scalar;  
       this->z += scalar;  
       return *this;  
   }  

   Vector3 operator*(float scalar) const { return {x * scalar, y * scalar, z * scalar}; }  
};
