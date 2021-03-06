/* 
 * 
 * Confidential Information of Telekinesys Research Limited (t/a Havok).  Not for disclosure or distribution without Havok's
 * prior written consent.This software contains code, techniques and know-how which is confidential and proprietary to Havok.
 * Level 2 and Level 3 source code contains trade secrets of Havok. Havok Software (C) Copyright 1999-2006 Telekinesys Research Limited t/a Havok. All Rights Reserved. Use of this software is subject to the terms of an end user license agreement.
 * 
 */

#ifndef HK_DYNAMICS2_STABILIZED_SPHERE_MOTION_H
#define HK_DYNAMICS2_STABILIZED_SPHERE_MOTION_H

#include <hkdynamics/motion/rigid/hkSphereMotion.h>

extern const hkClass hkStabilizedSphereMotionClass;

/// This class is contained by the hkRigidBody class.
/// It should not be accessed directly by the user.
class hkStabilizedSphereMotion : public hkSphereMotion
{
	public:

		HK_DECLARE_REFLECTION();

		hkStabilizedSphereMotion(const hkVector4& position, const hkQuaternion& rotation):
		  	hkSphereMotion( position, rotation )
			{
				m_type = MOTION_STABILIZED_SPHERE_INERTIA;
			}

	public:

		hkStabilizedSphereMotion( class hkFinishLoadedObjectFlag flag ) : hkSphereMotion( flag ) {}
};



#endif // HK_DYNAMICS2_STABILIZED_SPHERE_MOTION_H

/*
* Havok SDK - PUBLIC RELEASE, BUILD(#20060902)
*
* Confidential Information of Havok.  (C) Copyright 1999-2006 
* Telekinesys Research Limited t/a Havok. All Rights Reserved. The Havok
* Logo, and the Havok buzzsaw logo are trademarks of Havok.  Title, ownership
* rights, and intellectual property rights in the Havok software remain in
* Havok and/or its suppliers.
*
* Use of this software for evaluation purposes is subject to and indicates 
* acceptance of the End User licence Agreement for this product. A copy of 
* the license is included with this software and is also available from salesteam@havok.com.
*
*/
