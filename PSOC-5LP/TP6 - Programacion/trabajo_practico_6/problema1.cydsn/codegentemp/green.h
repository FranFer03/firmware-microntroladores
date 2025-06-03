/*******************************************************************************
* File Name: green.h  
* Version 2.20
*
* Description:
*  This file contains Pin function prototypes and register defines
*
* Note:
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_PINS_green_H) /* Pins green_H */
#define CY_PINS_green_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "green_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 green__PORT == 15 && ((green__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    green_Write(uint8 value);
void    green_SetDriveMode(uint8 mode);
uint8   green_ReadDataReg(void);
uint8   green_Read(void);
void    green_SetInterruptMode(uint16 position, uint16 mode);
uint8   green_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the green_SetDriveMode() function.
     *  @{
     */
        #define green_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define green_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define green_DM_RES_UP          PIN_DM_RES_UP
        #define green_DM_RES_DWN         PIN_DM_RES_DWN
        #define green_DM_OD_LO           PIN_DM_OD_LO
        #define green_DM_OD_HI           PIN_DM_OD_HI
        #define green_DM_STRONG          PIN_DM_STRONG
        #define green_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define green_MASK               green__MASK
#define green_SHIFT              green__SHIFT
#define green_WIDTH              1u

/* Interrupt constants */
#if defined(green__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in green_SetInterruptMode() function.
     *  @{
     */
        #define green_INTR_NONE      (uint16)(0x0000u)
        #define green_INTR_RISING    (uint16)(0x0001u)
        #define green_INTR_FALLING   (uint16)(0x0002u)
        #define green_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define green_INTR_MASK      (0x01u) 
#endif /* (green__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define green_PS                     (* (reg8 *) green__PS)
/* Data Register */
#define green_DR                     (* (reg8 *) green__DR)
/* Port Number */
#define green_PRT_NUM                (* (reg8 *) green__PRT) 
/* Connect to Analog Globals */                                                  
#define green_AG                     (* (reg8 *) green__AG)                       
/* Analog MUX bux enable */
#define green_AMUX                   (* (reg8 *) green__AMUX) 
/* Bidirectional Enable */                                                        
#define green_BIE                    (* (reg8 *) green__BIE)
/* Bit-mask for Aliased Register Access */
#define green_BIT_MASK               (* (reg8 *) green__BIT_MASK)
/* Bypass Enable */
#define green_BYP                    (* (reg8 *) green__BYP)
/* Port wide control signals */                                                   
#define green_CTL                    (* (reg8 *) green__CTL)
/* Drive Modes */
#define green_DM0                    (* (reg8 *) green__DM0) 
#define green_DM1                    (* (reg8 *) green__DM1)
#define green_DM2                    (* (reg8 *) green__DM2) 
/* Input Buffer Disable Override */
#define green_INP_DIS                (* (reg8 *) green__INP_DIS)
/* LCD Common or Segment Drive */
#define green_LCD_COM_SEG            (* (reg8 *) green__LCD_COM_SEG)
/* Enable Segment LCD */
#define green_LCD_EN                 (* (reg8 *) green__LCD_EN)
/* Slew Rate Control */
#define green_SLW                    (* (reg8 *) green__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define green_PRTDSI__CAPS_SEL       (* (reg8 *) green__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define green_PRTDSI__DBL_SYNC_IN    (* (reg8 *) green__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define green_PRTDSI__OE_SEL0        (* (reg8 *) green__PRTDSI__OE_SEL0) 
#define green_PRTDSI__OE_SEL1        (* (reg8 *) green__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define green_PRTDSI__OUT_SEL0       (* (reg8 *) green__PRTDSI__OUT_SEL0) 
#define green_PRTDSI__OUT_SEL1       (* (reg8 *) green__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define green_PRTDSI__SYNC_OUT       (* (reg8 *) green__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(green__SIO_CFG)
    #define green_SIO_HYST_EN        (* (reg8 *) green__SIO_HYST_EN)
    #define green_SIO_REG_HIFREQ     (* (reg8 *) green__SIO_REG_HIFREQ)
    #define green_SIO_CFG            (* (reg8 *) green__SIO_CFG)
    #define green_SIO_DIFF           (* (reg8 *) green__SIO_DIFF)
#endif /* (green__SIO_CFG) */

/* Interrupt Registers */
#if defined(green__INTSTAT)
    #define green_INTSTAT            (* (reg8 *) green__INTSTAT)
    #define green_SNAP               (* (reg8 *) green__SNAP)
    
	#define green_0_INTTYPE_REG 		(* (reg8 *) green__0__INTTYPE)
#endif /* (green__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_green_H */


/* [] END OF FILE */
