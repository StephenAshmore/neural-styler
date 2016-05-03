#include "global.h"

using namespace GClasses;
using std::endl;
using std::cout;

class Styler {
public:
	static const size_t BELIEF_SIZE = 24;
	static const size_t INPUT_SIZE = 50 * 50;
	static const size_t PIXEL_SIZE = 3;
	static const size_t ITERATIONS = 10e7;
	static const size_t RANDOM_SEED = 3232;
	static double LAMBA = 0.001; // regularization term
	
private:
	GNeuralNet m_encoder;
	GNeuralNet m_decoder;
	GMatrix m_trainingData;
	GRand m_rand;
	
public:
	Styler();			// Constructor: should setup encoder and decoder.
	void save(char* encoder_file, char* decoder_file); 	// Saves the models to a file.
	void load(char* encoder_file, char* decoder_file); 	// Loads the models from a file.
	void predict();		// should accept an image of some kind. GMatrix here, or accept a file and parse in the class?
	void train();		// trains the models
	void getTrainingData(GMatrix data);
	
protected:
	// helper functions:
};
