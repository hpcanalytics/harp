/* file: apriori_batch.h */
/*******************************************************************************
* Copyright 2014-2017 Intel Corporation
* All Rights Reserved.
*
* If this  software was obtained  under the  Intel Simplified  Software License,
* the following terms apply:
*
* The source code,  information  and material  ("Material") contained  herein is
* owned by Intel Corporation or its  suppliers or licensors,  and  title to such
* Material remains with Intel  Corporation or its  suppliers or  licensors.  The
* Material  contains  proprietary  information  of  Intel or  its suppliers  and
* licensors.  The Material is protected by  worldwide copyright  laws and treaty
* provisions.  No part  of  the  Material   may  be  used,  copied,  reproduced,
* modified, published,  uploaded, posted, transmitted,  distributed or disclosed
* in any way without Intel's prior express written permission.  No license under
* any patent,  copyright or other  intellectual property rights  in the Material
* is granted to  or  conferred  upon  you,  either   expressly,  by implication,
* inducement,  estoppel  or  otherwise.  Any  license   under such  intellectual
* property rights must be express and approved by Intel in writing.
*
* Unless otherwise agreed by Intel in writing,  you may not remove or alter this
* notice or  any  other  notice   embedded  in  Materials  by  Intel  or Intel's
* suppliers or licensors in any way.
*
*
* If this  software  was obtained  under the  Apache License,  Version  2.0 (the
* "License"), the following terms apply:
*
* You may  not use this  file except  in compliance  with  the License.  You may
* obtain a copy of the License at http://www.apache.org/licenses/LICENSE-2.0
*
*
* Unless  required  by   applicable  law  or  agreed  to  in  writing,  software
* distributed under the License  is distributed  on an  "AS IS"  BASIS,  WITHOUT
* WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
*
* See the   License  for the   specific  language   governing   permissions  and
* limitations under the License.
*******************************************************************************/

/*
//++
//  Implementation of the interface for the association rules algorithm
//--
*/
#ifndef __APRIORI_BATCH__
#define __APRIORI_BATCH__

#include "apriori_types.h"

namespace daal
{
namespace algorithms
{
namespace association_rules
{
namespace interface1
{

/**
 * Allocates memory for storing Association Rules algorithm results
 * \param[in] input         Pointer to input structure
 * \param[in] parameter     Pointer to parameter structure
 * \param[in] method        Computation method of the algorithm
 */
template <typename algorithmFPType>
DAAL_EXPORT services::Status Result::allocate(const daal::algorithms::Input *input, const daal::algorithms::Parameter *parameter, const int method)
{
    Parameter *algParameter = static_cast<Parameter *>(const_cast<daal::algorithms::Parameter *>(parameter));

    Argument::set(largeItemsets, data_management::SerializationIfacePtr(new data_management::HomogenNumericTable<size_t>(2, 0, data_management::NumericTableIface::notAllocate)));
    Argument::set(largeItemsetsSupport, data_management::SerializationIfacePtr(new data_management::HomogenNumericTable<size_t>(2, 0, data_management::NumericTableIface::notAllocate)));

    if(algParameter->discoverRules)
    {
        Argument::set(antecedentItemsets, data_management::SerializationIfacePtr(new data_management::HomogenNumericTable<size_t>(2, 0, data_management::NumericTableIface::notAllocate)));
        Argument::set(consequentItemsets, data_management::SerializationIfacePtr(new data_management::HomogenNumericTable<size_t>(2, 0, data_management::NumericTableIface::notAllocate)));
        Argument::set(confidence, data_management::SerializationIfacePtr(new data_management::HomogenNumericTable<algorithmFPType>(1, 0, data_management::NumericTableIface::notAllocate)));
    }
    return services::Status();
}

}// namespace interface1
}// namespace association_rules
}// namespace algorithms
}// namespace daal

#endif