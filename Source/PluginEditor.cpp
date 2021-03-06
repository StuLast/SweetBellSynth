/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
TapsynthTutorialsAudioProcessorEditor::TapsynthTutorialsAudioProcessorEditor (TapsynthTutorialsAudioProcessor& p, juce::AudioProcessorValueTreeState& vts)
    : AudioProcessorEditor (&p), audioProcessor (p), valueTreeState(vts)
{
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
    setSize (400, 300);
    
    attackSlider.setSliderStyle(juce::Slider::SliderStyle::LinearVertical);
    attackSlider.setRange(0.1, 5000);
    attackSlider.setTextBoxStyle(juce::Slider::TextBoxBelow, true, 20.0, 10.0);
    attackSlider.setValue(0.1);
    attackSliderAttachment.reset(new juce::AudioProcessorValueTreeState::SliderAttachment(valueTreeState, "attack", attackSlider));
    
    addAndMakeVisible(attackSlider);

}

TapsynthTutorialsAudioProcessorEditor::~TapsynthTutorialsAudioProcessorEditor()
{
}

//==============================================================================
void TapsynthTutorialsAudioProcessorEditor::paint (juce::Graphics& g)
{
}


void TapsynthTutorialsAudioProcessorEditor::resized()
{
    int margin(20);
    attackSlider.setBounds(10, 10, 40, 100);
}
