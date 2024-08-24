import React from 'react'
import '../assets/styles/Card.css'
import Katie from "../assets/images/download.png" 
import Star from "../assets/images/star.png"

const Card = (props) => {
    console.log(props)
  return (
    <div className='card'>
        <img src={Katie} />
        <div className='card__stats'>
            <img src={`../assets/images/${props.img}`} alt="" className='card__star'/>
            <span>{props.rating}</span>
            <span className='gray'>({props.reviewCount}) </span>
            <span className='gray'>{props.country}</span>

        </div>
        <p> {props.title} </p>
        <p><span className='bold'>From ${props.price}</span> /person</p>
    </div>
  )
}

export default Card

const nums = [1, 2, 3, 4, 5]
const doubled = nums.map((num) => {
    return num * 2
})


const names = ["alice", "bob", "charlie", "danielle"]

const upperCase =  names.map((name)=>{
    return name.toUpperCase()
})

const pokemon = ["Bulbasaur", "Charmander", "Squirtle"]
const elements = pokemon.map((mon)=>{
    return `<p>{mon}</p>`
})