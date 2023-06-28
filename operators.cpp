#include <iostream>

class mammal{
protected:
	virtual void display() {
		std::cout << weight << std::endl;
		std::cout << height << std::endl;
		std::cout << std::endl;
	}
public:
	int weight;
	int height;

	mammal() : weight(), height() {
		std::cerr << "fill all fields" << std::endl;
	}
	mammal(int w, int h) : weight(w),height(h) {
		display();
	}
	virtual ~mammal() {
		std::cout << "mammal class destructor" << std::endl;
	}
};

class lion : public mammal {
	std::string name;
public:
	lion() {
		std::cerr << "fill all fields" << std::endl;
	}
	lion(std::string n,int w,int h) : mammal(w,h), name(n) {
		display();
	}
	void display() override {
		std::cout << name << std::endl;
		std::cout << (this->weight / (this->height * this->height)) << std::endl;
		std::cout << std::endl;
	}
	lion(const lion& obj) {
		this->weight = obj.weight;
		this->height = obj.height;
		this->name = obj.name;
	}
	lion& operator = (const lion& obj) {
		this->weight = obj.weight;
		this->height = obj.height;
		this->name = obj.name;
		return *this;
	}
	void operator () (std::string n) {
		if (n == name)
		{
			std::cout << "object name is already '"<<n<<"'" << std::endl;
		}
		else {
			this->name = n;
			std::cout << "object name has been changed to '" << n << "'" << std::endl;
		}
	}
	bool operator < (const mammal* obj) {
		double bmi1 = this->weight / (this->height * this->height);
		double bmi2 = obj->weight / (obj->height * obj->height);
		return bmi1 < bmi2;
	}
	bool operator > (const mammal* obj) {
		double bmi1 = this->weight / (this->height * this->height);
		double bmi2 = obj->weight / (obj->height * obj->height);
		return bmi1 > bmi2;
	}
	~lion() override final {
		std::cout << "lion class destructor" << std::endl;
	}
};

class rabbit : public mammal {
	std::string name;
public:
	
	rabbit() {
		std::cerr << "fill all fields" << std::endl;
	}
	rabbit(std::string n, int w, int h) : mammal(w, h), name(n) {
		display();
	}
	void display() override final {
		std::cout << name << std::endl;
		std::cout << (this->weight / (this->height * this->height)) << std::endl;
		std::cout << std::endl;
	}
	rabbit(const rabbit& obj) {
		this->weight = obj.weight;
		this->height = obj.height;
		this->name = obj.name;
	}
	void operator () (std::string n) {
		if (n == name)
		{
			std::cout << "object name is already '" << n << "'" << std::endl;
		}
		else {
			this->name = n;
			std::cout << "object name has been changed to '" << n << "'" << std::endl;
		}
	}
	rabbit& operator = (const rabbit& obj) {
		this->weight = obj.weight;
		this->height = obj.height;
		this->name = obj.name;
		return *this;
	}
	bool operator < (const mammal* obj) {
		double bmi1 = this->weight / (this->height * this->height);
		double bmi2 = obj->weight / (obj->height * obj->height);
		return bmi1 < bmi2;
	}
	bool operator > (const mammal* obj) {
		double bmi1 = this->weight / (this->height * this->height);
		double bmi2 = obj->weight / (obj->height * obj->height);
		return bmi1 > bmi2;
	}

	~rabbit() override final {
		std::cout << "rabbit class destructor" << std::endl;
	}
};

int main() {
	/*mammal* L = new lion("lion", 250, 91);
	mammal* R = new rabbit("rabbit", 2, 40);

	if (L > R) {
		std::cout << "lion > rabbit" << std::endl;
	}
	else if (R > L) {
		std::cout << "lion < rabbit" << std::endl;
	}
	else {
		std::cout << "error" << std::endl;
	}  

	delete L;
	delete R;*/

	lion L("lion", 250, 91);

	L("lion");
	L.display();
}
