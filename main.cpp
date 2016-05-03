#include <iostream>

#include <GClasses/GMatrix>
#include <GClasses/GNeuralNet>

#include "Styler.h"

using namespace GCLasses;
using std::cout;
using std::endl;

int main()
{
	Styler picasso;
	
	picasso.train();
	
	
	
	// Create a neural network autoencoder using our inference method
	
	// lets just use a decoder that goes from:
	// beliefs to pixel.
	// trained using inference.
	
	// well we actually may need an encoder of some kind.
	// the issue is, how do we feed in the appropriate picture that we wish to have styled?
	
	// train on a bunch of images from van gogh or picasso or someone with iconic style.
	
	// see if when we feed in a different picture if it will predict a stylized version.
	
	
	return 0;
}