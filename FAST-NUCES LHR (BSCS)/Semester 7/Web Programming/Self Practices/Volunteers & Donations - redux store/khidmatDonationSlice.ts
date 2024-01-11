import {createSlice, PayloadAction} from '@reduxjs/toolkit'

export interface Donations{
    DonorName:string;
    date:string;
    area:string;
    cardType:string;
    amount:Float32Array;
}

interface DonationsState{
    donations:Donations[]
}

const initialState:DonationsState={
    donations:[],
};
const khidmatDonationSlice=createSlice({
name:'donationHistory',
initialState,
reducers:{
    updateDonations:(state,action:PayloadAction<Donations[]>)=>{
        state.donations=action.payload;
    },
},
});
export const {updateDonations}=khidmatDonationSlice.actions;
export default khidmatDonationSlice.reducer;


