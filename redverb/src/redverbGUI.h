/**
 *  This file is part of RedVerb.
 *
 *  RedVerb is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU Lesser General Public License as
 *  published by the Free Software Foundation, either version 3 of
 *  the License, or (at your option) any later version.
 *
 *  RedVerb is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU Lesser General Public License for more details.
 *
 *  You should have received a copy of the GNU Lesser General Public License
 *  along with RedVerb.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef REDVERBGUI_H
#define REDVERBGUI_H

#include "redverbEngine.h"
#include "RedverbLookAndFeel.h"


/**
 * @brief GUI for the reverb engine.
 *
 * This class handle the GUI part of the reverb. 
 */
class RedverbGUI   : public AudioProcessorEditor,
                              public ChangeListener,
                              public SliderListener
{
public:
    /** Constructor.

        When created, this will register itself with the filter for changes. It's
        safe to assume that the filter won't be deleted before this object is.
    */
    RedverbGUI (RedverbEngine* const ownerFilter);

    /** Destructor. */
    ~RedverbGUI();

    //==============================================================================
	/**
	 * @brief Called when parameter change occur.
	 */
    void changeListenerCallback (void* source);
	/**
	 * @brief Called when a slider is moved.
	 */
    void sliderValueChanged (Slider*);

    //==============================================================================
    /**
	 * @brief Callback for painting.
	 */
    void paint (Graphics& g);

    /**
	 * @brief Callback for resize.
	 */
    void resized();


private:
    //==============================================================================
	/**
	 * @brief Slider for the feedback.
	 */
	Slider* feedbackSlider;
	/**
	 * @brief Slider for the gain.
	 */
    Slider* gainSlider;
	/**
	 * @brief Slider for the delay length.
	 */
	Slider* delaySlider;
	/**
	 * @brief Example of a slider with custom graphics.
	 */
    Slider* customSlider;
	/**
	 * @brief To make the GUI resizable.
	 */
	ResizableCornerComponent* resizer;
	/**
	 * @brief To constraint the window size.
	 */
    ComponentBoundsConstrainer resizeLimits;
	/**
	 * @brief To add useful tooltips.
	 */ 
    TooltipWindow tooltipWindow;

	/**
     * @brief Get new parameters from filter.
	 */
    void updateParametersFromFilter();

    /**
	 * @brief Avoid the cast whenever needed.
	 */
    RedverbEngine* getFilter() const throw()       { return (RedverbEngine*) getAudioProcessor(); }
};


#endif