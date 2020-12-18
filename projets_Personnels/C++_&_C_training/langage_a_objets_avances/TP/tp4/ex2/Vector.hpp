#ifndef VECTOR_HPP
#define VECTOR_HPP
class Vector {
	int size;
	int *tab;
	static int mem;

	public:
	Vector(int taille);
	~Vector();
	void	print();
	int		get_at(int index);
	void	set_at(int index, int value);
	void	push_back(int value);
	void	push_front(int value);
	int		memoryTaken();
};

#endif