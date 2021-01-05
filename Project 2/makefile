project2: main.o employee.o employee_hash.o dept.o dept_hash.o project.o project_hash.o
	g++ -o project2 main.o employee.o employee_hash.o dept.o dept_hash.o project.o project_hash.o
main.o: main.cpp employee.o employee_hash.o dept.o dept_hash.o project.o project_hash.o 
	g++ -c -g main.cpp
employee_hash.o: employee_hash.cpp employee_hash.h employee.o
	g++ -c -g employee_hash.cpp
employee.o: employee.cpp employee_hash.h
	g++ -c -g employee.cpp
dept_hash.o: dept_hash.cpp dept_hash.h
	g++ -c -g dept_hash.cpp
dept.o: dept.cpp dept_hash.h
	g++ -c -g dept.cpp
project_hash.o: project_hash.cpp project_hash.h
	g++ -c -g project_hash.cpp
project.o: project.cpp project_hash.h
	g++ -c -g project.cpp
clean:
	rm -f *.o project2
run: project2
	./project2
