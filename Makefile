msg:
	@echo 'Targets are: '
	@echo 'producer'
	@echo 'consumer'
	@echo 'run'
	@echo 'clean'
consumer: ./consumer.cpp
	g++ "./consumer.cpp" -pthread -lrt -o ./out/consumer
producer: ./producer.cpp
	g++ "./producer.cpp" -pthread -lrt -o ./out/producer
run: ./
	make producer
	make consumer
	clear
	./out/producer shmfile & ./out/consumer shmfile
clean:
	rm -f ./out/consumer
	rm -f ./out/producer