/**
 * \file
 * \author Karsten Rink
 * \date   2012-05-02
 * \brief  Definition of the Cell class.
 *
 * \copyright
 * Copyright (c) 2012-2015, OpenGeoSys Community (http://www.opengeosys.org)
 *            Distributed under a Modified BSD License.
 *              See accompanying file LICENSE.txt or
 *              http://www.opengeosys.org/project/license
 *
 */

#ifndef CELL_H_
#define CELL_H_

#include "Element.h"

namespace MeshLib {

/**
 * Virtual base class for 3d mesh elements.
 */
class Cell : public Element
{
public:
	/// Constant: Dimension of this mesh element
	static const unsigned dimension = 3u;

	/// Get the volume of this 3d element.
	virtual double getVolume() const { return getContent(); }

	/// Destructor
	virtual ~Cell();

	/**
	 * Checks if the node order of an element is correct by testing surface normals.
	 * For 3D elements true is returned if the normals of all faces points away from the centre of 
	 * the element.
	 * Note: This method might give wrong results if something else is wrong with the element 
	 * (non-planar faces, non-convex geometry, possibly zero volume) which causes the calculated 
	 * center of gravity to lie outside of the actual element
	 */
	virtual bool testElementNodeOrder() const;

protected:
	/// Constructor
	/// @param value  element value
	/// @param id     element id
	Cell(unsigned value, std::size_t id);
}; /* class */

}

#endif /* CELL_H_ */

