#ifndef DATA_GENERATION_BLOCK_H
#define DATA_GENERATION_BLOCK_H

#include <fstream>
#include <string>

#include "include/iprocess_block.hpp"
#include "include/lock_free_queue.hpp"
#include "include/ring_buffer.hpp"

using byte = unsigned char;

class DataGenerationBlock : public IProcessBlock {
public:
	DataGenerationBlock() = default;
	DataGenerationBlock(std::string csvPath, RingBuffer &buffer, Queue *inputQueue, Queue *outputQueue);
	virtual ~DataGenerationBlock() = default;

	bool hasMoreData();
	std::pair<byte, byte> readCSV();
	std::pair<byte, byte> generateRandomNumbers();

	void execute() override;
private:
	std::ifstream _file;
	std::string _csvPath;

	RingBuffer *_buffer;
	Queue *_inputQueue;
	Queue *_outputQueue;
};

#endif // DATA_GENERATION_BLOCK_H
