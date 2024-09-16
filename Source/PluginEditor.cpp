/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
ConvolutionReverbAudioProcessorEditor::ConvolutionReverbAudioProcessorEditor (ConvolutionReverbAudioProcessor& p)
    : AudioProcessorEditor (&p), audioProcessor (p)
{
    // Add gain slider
    addAndMakeVisible(gainSlider);
    gainSlider.setRange(0.0, 1.0, 0.01); // Min, Max, Step
    gainSlider.setValue(*audioProcessor.gainParameter); // Set initial value
    gainSlider.onValueChange = [this] {
        *audioProcessor.gainParameter = gainSlider.getValue(); // Update parameter when slider changes
        };


    setSize (400, 300);
}

ConvolutionReverbAudioProcessorEditor::~ConvolutionReverbAudioProcessorEditor()
{
}

//==============================================================================
void ConvolutionReverbAudioProcessorEditor::paint (juce::Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (getLookAndFeel().findColour (juce::ResizableWindow::backgroundColourId));

   
}

void ConvolutionReverbAudioProcessorEditor::resized()
{
    gainSlider.setBounds(getWidth() / 2 - 100, getHeight() / 2 - 100, 200, 200); // Center the gain slider
}
