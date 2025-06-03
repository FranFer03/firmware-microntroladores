/*******************************************************************************
* File Name: Cloack.h
* Version 2.20
*
*  Description:
*   Provides the function and constant definitions for the clock component.
*
*  Note:
*
********************************************************************************
* Copyright 2008-2012, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_CLOCK_Cloack_H)
#define CY_CLOCK_Cloack_H

#include <cytypes.h>
#include <cyfitter.h>


/***************************************
* Conditional Compilation Parameters
***************************************/

/* Check to see if required defines such as CY_PSOC5LP are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5LP)
    #error Component cy_clock_v2_20 requires cy_boot v3.0 or later
#endif /* (CY_PSOC5LP) */


/***************************************
*        Function Prototypes
***************************************/

void Cloack_Start(void) ;
void Cloack_Stop(void) ;

#if(CY_PSOC3 || CY_PSOC5LP)
void Cloack_StopBlock(void) ;
#endif /* (CY_PSOC3 || CY_PSOC5LP) */

void Cloack_StandbyPower(uint8 state) ;
void Cloack_SetDividerRegister(uint16 clkDivider, uint8 restart) 
                                ;
uint16 Cloack_GetDividerRegister(void) ;
void Cloack_SetModeRegister(uint8 modeBitMask) ;
void Cloack_ClearModeRegister(uint8 modeBitMask) ;
uint8 Cloack_GetModeRegister(void) ;
void Cloack_SetSourceRegister(uint8 clkSource) ;
uint8 Cloack_GetSourceRegister(void) ;
#if defined(Cloack__CFG3)
void Cloack_SetPhaseRegister(uint8 clkPhase) ;
uint8 Cloack_GetPhaseRegister(void) ;
#endif /* defined(Cloack__CFG3) */

#define Cloack_Enable()                       Cloack_Start()
#define Cloack_Disable()                      Cloack_Stop()
#define Cloack_SetDivider(clkDivider)         Cloack_SetDividerRegister(clkDivider, 1u)
#define Cloack_SetDividerValue(clkDivider)    Cloack_SetDividerRegister((clkDivider) - 1u, 1u)
#define Cloack_SetMode(clkMode)               Cloack_SetModeRegister(clkMode)
#define Cloack_SetSource(clkSource)           Cloack_SetSourceRegister(clkSource)
#if defined(Cloack__CFG3)
#define Cloack_SetPhase(clkPhase)             Cloack_SetPhaseRegister(clkPhase)
#define Cloack_SetPhaseValue(clkPhase)        Cloack_SetPhaseRegister((clkPhase) + 1u)
#endif /* defined(Cloack__CFG3) */


/***************************************
*             Registers
***************************************/

/* Register to enable or disable the clock */
#define Cloack_CLKEN              (* (reg8 *) Cloack__PM_ACT_CFG)
#define Cloack_CLKEN_PTR          ((reg8 *) Cloack__PM_ACT_CFG)

/* Register to enable or disable the clock */
#define Cloack_CLKSTBY            (* (reg8 *) Cloack__PM_STBY_CFG)
#define Cloack_CLKSTBY_PTR        ((reg8 *) Cloack__PM_STBY_CFG)

/* Clock LSB divider configuration register. */
#define Cloack_DIV_LSB            (* (reg8 *) Cloack__CFG0)
#define Cloack_DIV_LSB_PTR        ((reg8 *) Cloack__CFG0)
#define Cloack_DIV_PTR            ((reg16 *) Cloack__CFG0)

/* Clock MSB divider configuration register. */
#define Cloack_DIV_MSB            (* (reg8 *) Cloack__CFG1)
#define Cloack_DIV_MSB_PTR        ((reg8 *) Cloack__CFG1)

/* Mode and source configuration register */
#define Cloack_MOD_SRC            (* (reg8 *) Cloack__CFG2)
#define Cloack_MOD_SRC_PTR        ((reg8 *) Cloack__CFG2)

#if defined(Cloack__CFG3)
/* Analog clock phase configuration register */
#define Cloack_PHASE              (* (reg8 *) Cloack__CFG3)
#define Cloack_PHASE_PTR          ((reg8 *) Cloack__CFG3)
#endif /* defined(Cloack__CFG3) */


/**************************************
*       Register Constants
**************************************/

/* Power manager register masks */
#define Cloack_CLKEN_MASK         Cloack__PM_ACT_MSK
#define Cloack_CLKSTBY_MASK       Cloack__PM_STBY_MSK

/* CFG2 field masks */
#define Cloack_SRC_SEL_MSK        Cloack__CFG2_SRC_SEL_MASK
#define Cloack_MODE_MASK          (~(Cloack_SRC_SEL_MSK))

#if defined(Cloack__CFG3)
/* CFG3 phase mask */
#define Cloack_PHASE_MASK         Cloack__CFG3_PHASE_DLY_MASK
#endif /* defined(Cloack__CFG3) */

#endif /* CY_CLOCK_Cloack_H */


/* [] END OF FILE */
