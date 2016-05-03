#include <iostream>

#include <GClasses/GNeuralNet>
#include <GClasses/GMatrix>

using namespace GClasses;
using std::endl;
using std::cout;

class Styler {
private:
	GNeuralNet m_encoder;
	GNeuralNet m_decoder;
	
	
public:
	Styler();			// Constructor: should setup encoder and decoder.
	void save(char* encoder_file, char* decoder_file); 	// Saves the models to a file.
	void load(char* encoder_file, char* decoder_file); 	// Loads the models from a file.
	void predict();		// should accept an image of some kind. GMatrix here, or accept a file and parse in the class?
	void train();		// trains the models
	
protected:
	// helper functions:
};