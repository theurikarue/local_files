import React from 'react'

const Joke = (props) => {
    console.log(props)
    console.log(props.isPun)
  return (
    <>
        { props.setup && <h3>Setup: {props.setup}</h3>}
        <p> Punchline:{props.punchline}</p>
        <p> {props.isPun} </p>
    </>
  )
}

export default Joke