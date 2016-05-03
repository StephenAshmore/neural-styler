#include "Styler.h"

Styler::Styler()
: m_rand(Styler::RANDOM_SEED)
{
	GUniformRelation r_inputs(Styler::INPUT_SIZE);
	GUniformRelation r_beliefs(Styler::BELIF_SIZE);
	GUniformRelation r_pixel(Styler::PIXEL_SIZE);
	
	// initialize the encoder
	m_encoder.addLayer(new GLayerClassic(Styler::INPUT_SIZE, 300, new GActivationBentIdentity()));
	m_encoder.addLayer(new GLayerClassic(FLEXIBLE_SIZE, 100, new GActivationBentIdentity()));
	m_encoder.addLayer(new GLayerClassic(FLEXIBLE_SIZE, Styler::BELIEF_SIZE, new GActivationBentIdentity()));
	m_encoder.beginIncrementalLearning(r_inputs, r_beliefs);
	
	// initialize the decoder
	m_decoder.addLayer(new GLayerClassic(Styler::BELIEF_SIZE, 256, new GActivationBentIdentity()));
	m_decoder.addLayer(new GLayerClassic(FLEXIBLE_SIZE, 512, new GActivationBentIdentity()));
	m_decoder.addLayer(new GLayerClassic(FLEXIBLE_SIZE, 256, new GActivationBentIdentity()));
	m_decoder.addLayer(new GLayerClassic(FLEXIBLE_SIZE, Styler::PIXEL_SIZE, new GActivationBentIdentity()));
	m_decoder.beginIncrementalLearning(r_beliefs, r_pixel);
}

void Styler::save(char* encoder_file, char* decoder_file)
{
	throw("Unimplemented.");
}

void Styler::load(char* encoder_file, char* decoder_file)
{
	throw("Unimplemented.");
}

void Styler::predict()
{
	
}

void Styler::train()
{
	if ( m_trainingData.rows() < 1 )
		throw("Error: Training Data has not been initialized. You must create training data before calling train.");
	
	size_t row = 0;
	
	for ( size_t iter = 0; iter < Styler::ITERATIONS; iter++ )
	{
		row = m_rand.next(m_trainingData.rows());
		std::cerr << "Iteration: " << iter << endl;
		
	}
}
