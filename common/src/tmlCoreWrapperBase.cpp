/* 
 *  libTML:  A BEEP based Messaging Suite
 *  Copyright (C) 2015 wobe-systems GmbH
 *
 *  This program is free software; you can redistribute it and/or
 *  modify it under the terms of the GNU Lesser General Public License
 *  as published by the Free Software Foundation; either version 2.1
 *  of the License, or (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 *  Lesser General Public License for more details.
 *
 *  You should have received a copy of the GNU Lesser General Public
 *  License along with this program; if not, write to the Free
 *  Software Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA
 *  02111-1307 USA
 *  
 *  You may find a copy of the license under this software is released
 *  at COPYING file. This is LGPL software: you are welcome to develop
 *  proprietary applications using this library without any royalty or
 *  fee but returning back any change, improvement or addition in the
 *  form of source code, project image, documentation patches, etc.
 *
 *  Homepage:
 *    http://www.libtml.org
 *
 *  For professional support contact us:
 *
 *    wobe-systems GmbH
 *    support@libtml.org
 *
 * Contributors:
 *    wobe-systems GmbH
 */

#include "tmlCoreWrapperBase.h"


/**
 * @brief    Constructor.
 */
tmlCoreWrapperBase::tmlCoreWrapperBase()
{
  m_ctx = NULL;
  m_pTLS_AcceptCB = NULL;
  m_pTLS_CertReqCB = NULL;
  m_pTLS_PrivateKeyReqCB = NULL;
}


/**
 * @brief    Destructor.
 */
tmlCoreWrapperBase::~tmlCoreWrapperBase()
{
  m_ctx = NULL;
}


/**
 * @brief    Get the Vortex execution context
 */
VortexCtx* tmlCoreWrapperBase::getVortexCtx(){
  return m_ctx;
}


/**
  * @brief   Set the TLS accept callback method
  */
void tmlCoreWrapperBase::setTlsAcceptCB(void* pAcceptCB){
  m_pTLS_AcceptCB = pAcceptCB; 
}


/**
  * @brief   Get the TLS accept callback method
  */
void* tmlCoreWrapperBase::getTlsAcceptCB(){
  return m_pTLS_AcceptCB; 
}


/**
  * @brief   Set the TLS certifiction file request callback method
  */
void tmlCoreWrapperBase::setTlsCertReqCB(void* pCertReqCB){
  m_pTLS_CertReqCB = pCertReqCB; 
}


/**
  * @brief   Get the TLS certifiction file request callback method
  */
void* tmlCoreWrapperBase::getTlsCertReqCB(){
  return m_pTLS_CertReqCB;
}


/**
  * @brief   Set the TLS private key file request callback method
  */
void tmlCoreWrapperBase::setTlsPrivateKeyReqCB(void* pPrivateKeyReqCB){
  m_pTLS_PrivateKeyReqCB = pPrivateKeyReqCB; 
}

/**
  * @brief   Get the TLS private key file request callback method
  */
void* tmlCoreWrapperBase::getTlsPrivateKeyReqCB(){
  return m_pTLS_PrivateKeyReqCB; 
}