/*******************************************************************************
* File Name: Bomb.h  
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

#if !defined(CY_PINS_Bomb_H) /* Pins Bomb_H */
#define CY_PINS_Bomb_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "Bomb_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 Bomb__PORT == 15 && ((Bomb__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    Bomb_Write(uint8 value);
void    Bomb_SetDriveMode(uint8 mode);
uint8   Bomb_ReadDataReg(void);
uint8   Bomb_Read(void);
void    Bomb_SetInterruptMode(uint16 position, uint16 mode);
uint8   Bomb_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the Bomb_SetDriveMode() function.
     *  @{
     */
        #define Bomb_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define Bomb_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define Bomb_DM_RES_UP          PIN_DM_RES_UP
        #define Bomb_DM_RES_DWN         PIN_DM_RES_DWN
        #define Bomb_DM_OD_LO           PIN_DM_OD_LO
        #define Bomb_DM_OD_HI           PIN_DM_OD_HI
        #define Bomb_DM_STRONG          PIN_DM_STRONG
        #define Bomb_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define Bomb_MASK               Bomb__MASK
#define Bomb_SHIFT              Bomb__SHIFT
#define Bomb_WIDTH              1u

/* Interrupt constants */
#if defined(Bomb__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in Bomb_SetInterruptMode() function.
     *  @{
     */
        #define Bomb_INTR_NONE      (uint16)(0x0000u)
        #define Bomb_INTR_RISING    (uint16)(0x0001u)
        #define Bomb_INTR_FALLING   (uint16)(0x0002u)
        #define Bomb_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define Bomb_INTR_MASK      (0x01u) 
#endif /* (Bomb__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define Bomb_PS                     (* (reg8 *) Bomb__PS)
/* Data Register */
#define Bomb_DR                     (* (reg8 *) Bomb__DR)
/* Port Number */
#define Bomb_PRT_NUM                (* (reg8 *) Bomb__PRT) 
/* Connect to Analog Globals */                                                  
#define Bomb_AG                     (* (reg8 *) Bomb__AG)                       
/* Analog MUX bux enable */
#define Bomb_AMUX                   (* (reg8 *) Bomb__AMUX) 
/* Bidirectional Enable */                                                        
#define Bomb_BIE                    (* (reg8 *) Bomb__BIE)
/* Bit-mask for Aliased Register Access */
#define Bomb_BIT_MASK               (* (reg8 *) Bomb__BIT_MASK)
/* Bypass Enable */
#define Bomb_BYP                    (* (reg8 *) Bomb__BYP)
/* Port wide control signals */                                                   
#define Bomb_CTL                    (* (reg8 *) Bomb__CTL)
/* Drive Modes */
#define Bomb_DM0                    (* (reg8 *) Bomb__DM0) 
#define Bomb_DM1                    (* (reg8 *) Bomb__DM1)
#define Bomb_DM2                    (* (reg8 *) Bomb__DM2) 
/* Input Buffer Disable Override */
#define Bomb_INP_DIS                (* (reg8 *) Bomb__INP_DIS)
/* LCD Common or Segment Drive */
#define Bomb_LCD_COM_SEG            (* (reg8 *) Bomb__LCD_COM_SEG)
/* Enable Segment LCD */
#define Bomb_LCD_EN                 (* (reg8 *) Bomb__LCD_EN)
/* Slew Rate Control */
#define Bomb_SLW                    (* (reg8 *) Bomb__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define Bomb_PRTDSI__CAPS_SEL       (* (reg8 *) Bomb__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define Bomb_PRTDSI__DBL_SYNC_IN    (* (reg8 *) Bomb__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define Bomb_PRTDSI__OE_SEL0        (* (reg8 *) Bomb__PRTDSI__OE_SEL0) 
#define Bomb_PRTDSI__OE_SEL1        (* (reg8 *) Bomb__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define Bomb_PRTDSI__OUT_SEL0       (* (reg8 *) Bomb__PRTDSI__OUT_SEL0) 
#define Bomb_PRTDSI__OUT_SEL1       (* (reg8 *) Bomb__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define Bomb_PRTDSI__SYNC_OUT       (* (reg8 *) Bomb__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(Bomb__SIO_CFG)
    #define Bomb_SIO_HYST_EN        (* (reg8 *) Bomb__SIO_HYST_EN)
    #define Bomb_SIO_REG_HIFREQ     (* (reg8 *) Bomb__SIO_REG_HIFREQ)
    #define Bomb_SIO_CFG            (* (reg8 *) Bomb__SIO_CFG)
    #define Bomb_SIO_DIFF           (* (reg8 *) Bomb__SIO_DIFF)
#endif /* (Bomb__SIO_CFG) */

/* Interrupt Registers */
#if defined(Bomb__INTSTAT)
    #define Bomb_INTSTAT            (* (reg8 *) Bomb__INTSTAT)
    #define Bomb_SNAP               (* (reg8 *) Bomb__SNAP)
    
	#define Bomb_0_INTTYPE_REG 		(* (reg8 *) Bomb__0__INTTYPE)
#endif /* (Bomb__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_Bomb_H */


/* [] END OF FILE */
