/* 
 * 
 * Confidential Information of Telekinesys Research Limited (t/a Havok).  Not for disclosure or distribution without Havok's
 * prior written consent.This software contains code, techniques and know-how which is confidential and proprietary to Havok.
 * Level 2 and Level 3 source code contains trade secrets of Havok. Havok Software (C) Copyright 1999-2006 Telekinesys Research Limited t/a Havok. All Rights Reserved. Use of this software is subject to the terms of an end user license agreement.
 * 
 */

#ifndef HK_DYNAMICS2_DYNAMICS_CONTACT_MGR_H
#define HK_DYNAMICS2_DYNAMICS_CONTACT_MGR_H

#include <hkcollide/agent/hkContactMgr.h>

class hkContactPoint;
class hkContactPointProperties;
class hkVector4;


///An interface to access contact point information.
class hkDynamicsContactMgr: public hkContactMgr
{
	public:

		enum Type
		{
			TYPE_SIMPLE_CONSTRAINT_CONTACT_MGR,
			TYPE_REPORT_CONTACT_MGR
		};

		hkDynamicsContactMgr() {}

			/// Gets the properties attached to the contact point (if available)
		virtual hkContactPointProperties* getContactPointProperties( hkContactPointId id ){ return HK_NULL;}

			/// Gets the dynamics contact point (if available)
		virtual hkContactPoint* getContactPoint( hkContactPointId id ){ return HK_NULL;}

			/// Gets the ids of all contact points in this collision
		virtual void getAllContactPointIds( hkArray<hkContactPointId>& contactPointIds ) const {}

		virtual Type getType() = 0;

			/// Virtual function which is called just before a simple collision response is executed 
			/// in a TOI. The default implementation will forward this to the hkSimpleContactConstraintData::collisionResponseBeginCallback.
			/// This is used for the mass changer and moving surface utility
		virtual void toiCollisionResponseBeginCallback( const hkContactPoint& cp, struct hkSimpleConstraintInfoInitInput& inA, struct hkBodyVelocity& velA, hkSimpleConstraintInfoInitInput& inB, hkBodyVelocity& velB){}

			/// Virtual function which is called just after a simple collision response is executed 
			/// The default implementation will forward this to the hkSimpleContactConstraintData::collisionResponseEndCallback.
			/// This is used for the mass changer and moving surface utility
		virtual void toiCollisionResponseEndCallback( const hkContactPoint& cp, hkReal impulseApplied, struct hkSimpleConstraintInfoInitInput& inA, struct hkBodyVelocity& velA, hkSimpleConstraintInfoInitInput& inB, hkBodyVelocity& velB){}

			/// Return the constraint if there is one 
		virtual class hkConstraintInstance* getConstraintInstance() { return HK_NULL; } 

	protected:
		class hkWorld*					m_world;
};

#endif // HK_DYNAMICS2_DYNAMICS_CONTACT_MGR_H

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
