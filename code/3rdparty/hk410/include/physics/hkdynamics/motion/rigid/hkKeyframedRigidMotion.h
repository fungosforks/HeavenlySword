/* 
 * 
 * Confidential Information of Telekinesys Research Limited (t/a Havok).  Not for disclosure or distribution without Havok's
 * prior written consent.This software contains code, techniques and know-how which is confidential and proprietary to Havok.
 * Level 2 and Level 3 source code contains trade secrets of Havok. Havok Software (C) Copyright 1999-2006 Telekinesys Research Limited t/a Havok. All Rights Reserved. Use of this software is subject to the terms of an end user license agreement.
 * 
 */

#ifndef HK_DYNAMICS2_KEYFRAMED_RIGID_MOTION
#define HK_DYNAMICS2_KEYFRAMED_RIGID_MOTION

#include <hkdynamics/motion/hkMotion.h>

extern const hkClass hkKeyframedRigidMotionClass;

/// This class is contained by the hkRigidBody class.
/// It should not be accessed directly by the user.
class hkKeyframedRigidMotion : public hkMotion
{
	public:

		HK_DECLARE_REFLECTION();

			/// Construct a keyframed rigid body motion object, given position and rotation.
			/// Set the mass and the inertia to be infinite to achieve the
			/// special behaviour of the keyframed motion. This is a property
			/// of the keyframed motion and should not be changed.
		hkKeyframedRigidMotion( const hkVector4& position, const hkQuaternion& rotation );

		~hkKeyframedRigidMotion();

			/// Set the mass of the rigid body. (Note: it is better to use setMassInv if possible).
		virtual void setMass(hkReal m);

			/// Set the inverse mass of the rigid body. 
		virtual void setMassInv(hkReal mInv);

		/*
		** INERTIA
		*/

			/// Get the inertia tensor of the rigid body in local space.
		virtual void getInertiaLocal(hkMatrix3& inertia) const;

			/// Users should not set the inertia of a keyframed body.
			/// This will result in an ASSERT.  Inertia is infinite for keyframed bodies.
		virtual void setInertiaLocal(const hkMatrix3& inertia);

			/// Get the inertia tensor of the rigid body in world space.
		virtual void getInertiaWorld(hkMatrix3& inertiaOut) const;

			/// Users should not set the inertia inverse of a keyframed body.
			/// This will result in an ASSERT.  Inertia is infinite for keyframed bodies.
		virtual void setInertiaInvLocal(const hkMatrix3& inertiaInv);

			/// Get the inverse inertia tensor in local space.
		virtual void getInertiaInvLocal(hkMatrix3& inertiaInv) const;

			/// Get the inverse inertia tensor in local space.
		virtual void getInertiaInvWorld(hkMatrix3& inertiaInvOut) const;


		/*
		** IMPULSE APPLICATION
		*/

		
			/// Users should not apply a linear impulse to a keyframed body. Try setting the velocity instead.
			/// Keyframed bodies are infinitely heavy so applying impulses doesn't have any effect.
		virtual void applyLinearImpulse(const hkVector4& imp);

			/// Users should not apply a point impulse to a keyframed body. Try setting the velocity instead.
			/// Keyframed bodies are infinitely heavy so applying impulses doesn't have any effect.
		virtual void applyPointImpulse(const hkVector4& imp, const hkVector4& p);

			/// Users should not apply an angular impulse to a keyframed body. Try setting the angular velocity instead.
			/// Keyframed bodies are infinitely heavy so applying angular impulses doesn't have any effect.
		virtual void applyAngularImpulse(const hkVector4& imp);


		/*
		** FORCE AND TORQUE APPLICATION
		*/

			/// Users should not apply a force to a keyframed body. Try setting the velocity instead.
			/// Keyframed bodies are infinitely heavy so applying forces doesn't have any effect.
		virtual void applyForce(const hkReal deltaTime, const hkVector4& force);

			/// Users should not apply a force to a keyframed body.  Try setting the velocity instead.
			/// Keyframed bodies are infinitely heavy so applying forces doesn't have any effect.
		virtual void applyForce(const hkReal deltaTime, const hkVector4& force, const hkVector4& p);

			/// Users should not apply a torque to a keyframed body.  Try setting the angular velocity instead.
			/// Keyframed bodies are infinitely heavy so applying torque doesn't have any effect.
		virtual void applyTorque(const hkReal deltaTime, const hkVector4& torque);

	protected:

		hkKeyframedRigidMotion(): hkMotion(hkFinishLoadedObjectFlag()){ m_savedMotion = HK_NULL; }

	public:

			// Stored _DYNAMIC_ motion
		class hkMaxSizeMotion*	m_savedMotion;

			// Stored quality type of the rigid body, which refers to its saved _DYNAMIC_ motion.
		int m_savedQualityTypeIndex;

	public:

		// hkMotion interface

		virtual void setStepPosition( hkReal position, hkReal timestep );

		virtual void setStoredMotion( hkMaxSizeMotion* savedMotion );

	public:

		hkKeyframedRigidMotion( class hkFinishLoadedObjectFlag flag ) : hkMotion( flag ) {}
};



// This class is just used as a large-enough placeholder for all available motion classes
class hkMaxSizeMotion : public hkKeyframedRigidMotion
{
	public:
		HK_DECLARE_REFLECTION();

		hkMaxSizeMotion() : hkKeyframedRigidMotion( ) {}
		hkMaxSizeMotion( class hkFinishLoadedObjectFlag flag ) : hkKeyframedRigidMotion( flag ) {}
	private:
		void operator=(const hkMaxSizeMotion& other);
		hkMaxSizeMotion( const hkMaxSizeMotion& other );
};





#endif //HK_DYNAMICS2_KEYFRAMED_RIGID_MOTION

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
